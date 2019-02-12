/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Sameer Naumani
 *
 * Created on February 11, 2019, 4:57 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

char c[100];
char c1[100];
char c2[100];
int i,j=0,k=0;
int flag = 0;
int length;
int main(int argc, char** argv)
{
    printf(" enter your pipe command:\n");
    fgets(c, 100, stdin);
    
    length = strlen(c) - 1;
    for (i=0;i<length;i++){
        if (c[i] != '|' && flag == 0){
            c1[j] = c[i];
            j++;
        }
        else if(c[i] == '|') {
            flag = 1;
            i++;
        }
        else{
            c2[k] = c[i];
            k++;
        }
    }
    
    int fd[2];
    pipe(fd);
    if (fork()==0){
        dup2(fd[1],1);
        close(fd[0]);
        system(c1);
        exit(0);
    }
    else{
        dup2(fd[0],0);
        close(fd[1]);
        system(c2);
    }
    
    return (EXIT_SUCCESS);
}
