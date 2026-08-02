/**
 * Pregunta de exsamen cuatos  procesos hijo se crean ?
 * a) 3  b) 4 c) 7 d) 8 
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t pid; 

    pid = fork();
    pid = fork();
    pid = fork();
    printf("PID : %d,PPID: %d\n",getpid(),getppid());
    sleep(1); 
    return EXIT_SUCCESS;
}