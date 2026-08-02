/*Objetivo del ejemplo 
Conocer el uso de getpid(), getPpit(); 

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define ROJO "\x1b[31m"
#define VERDE "\x1b[32m"
#define AZUL "\x1b[34m"
#define BLANCO "\x1b[97m"


int main(){

    pid_t pid; 
    pid = fork(); 
    printf ("pid: %\n",pid); 
    if(pid == 0) { // es el proceso hijo 
        printf(VERDE "HIJO : Getpid() , o sea PID del proceso hijo: %d \n " RESET ,getpid()); usleep(10); 
        printf(VERDE, "HIJO: getppid(), o sea PID del proceso padre: %d\n " RESET, getppid()); usleep(10); 
        exit(EXIT_SUCCESS);  
    }else if (pid >0){ // proceso padre
        printf(BLANCO "PADRE : pid recibido del fork(), es decir PID del proceso hijo: %d\n " RESET,pid); usleep(10); 
        printf (BLANCO, "PADRE: getpid() o sea PID del proceso padre : %d\n",RESET,getpid()); usleep(10);
        printf(BLANCO, "PADRE: getppid() o sea PID del proceso padre del padre : %d\n" RESET,getppid()); usleep(10);
        

    }else{
        perror("fork"); 
        exit(EXIT_FAIURE); 

    }
    return EXIT_SUCCESS;
}