/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Sameer Naumani
 *
 * Created on February 3, 2019, 11:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    while(1){
        printf("Your Command>>> \n");
        char command[20];
        fgets(command,20,stdin);
        int last = strlen(command) - 1;
        char last_c = command[last-1];
        //process id
        pid_t pids[10];
        int i,j;
        int count = 0;
    
    for(i=0; i<1; i++)
    {
        
        pid_t pid = fork();
        pids[i] = pid;
        if(pid == 0){
            system(command);
            printf("%d\n",1);
            exit(0);
        }
        else
            continue;
    }
        
    if(last_c != '&')
    {
        for(i=0; i<1; i++)
        {
            pid_t pid = pids[i];
            waitpid(pid,NULL,0); 
        }
        printf("done waiting for child to complete\n");
    }
    else
        printf("Waiting for child to complete\n");
        
    }
}
   


