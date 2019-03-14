/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Sameer Naumani
 *
 * Created on February 21, 2019, 5:04 PM
 */


#include <stdio.h>
#include <stdlib.h>     /* NULL */
#include <stdio.h>	/* printf */
#include <sys/types.h>	/* pid_t */
#include <unistd.h>	/* get_pid */
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <sys/wait.h> 	/* wait */
#include <pthread.h>

#define PRODUCER_NO 5	//Number of producers
#define NUM_PRODUCED 2000 //Number of items to be produced

void *generator_function(void *arg1);
void *print_function(void *arg2);
long sum; /* Sum of generated values*/
long finished_producers; /* number of the producer that finished producing */

//C: Mutex declaration and initialization

pthread_mutex_t mutex_stdout = PTHREAD_MUTEX_INITIALIZER;


//F: Condition variable declaration and initialization

pthread_cond_t cond_stdout = PTHREAD_COND_INITIALIZER;

int main(void) {
    /* initialize random seed: */
    srand(time(NULL));
    sum = 0;
    pthread_t generatorThread[5];
    pthread_t print_function_Thread;
    int i, th, th2;
    //A: Creates five generator thread
    
    for (i=0; i<5; i++){
        th = pthread_create(&generatorThread[i], NULL, &generator_function, NULL);
    }
    
    //D: Creates print thread
    
    th2 = pthread_create(&print_function_Thread, NULL, &print_function, NULL);
    
    
    //B: Makes sure that all generator threads has finished before proceeding
    
    for (i=0; i<5; i++){
        pthread_join(generatorThread[i], NULL);
    }
    
    //E: Makes sure that print thread has finished before proceeding
    
    pthread_join(print_function_Thread, NULL);
    return (0);
    
}

void *generator_function(void *arg1) {
    
    long counter = 0;
    long sum_this_generator = 0;
    
    pthread_mutex_lock(&mutex_stdout);
    while (counter < 20L) {
        
        long tmpNumber = sum;
        long rnd_number = 1;
        printf("current sum of the generated number up to now is %ld going to add %ld to it.\n", tmpNumber, rnd_number);
        sum = tmpNumber + rnd_number;
        counter++;
        sum_this_generator += rnd_number;
        usleep(1000);
    }
    pthread_mutex_unlock(&mutex_stdout);
    printf("--+---+----+----------+---------+---+--+---+------+----\n");
    printf("The sum of produced items for this number generator at the end is: %ld \n", sum_this_generator);
    printf("--+---+----+----------+---------+---+--+---+------+----\n");
    finished_producers++;
    //H: If all generator has finished fire signal for condition variable
    
    if (finished_producers == 5){
        pthread_cond_signal(&cond_stdout);
    }
    return (0);
}

void *print_function(void *arg2) {
    //G: Wait until all generator has finished
    
    pthread_mutex_lock(&mutex_stdout);
    
    if (finished_producers == 0){
        pthread_cond_wait(&cond_stdout, &mutex_stdout);
    }
    pthread_mutex_unlock(&mutex_stdout);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("The value of counter at the end is: %ld \n", sum);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
}