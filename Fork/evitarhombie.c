/**
 * Ejemplos para evitar procesos hombies 
 */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int estado; 
    pid_t pid; 

    pid = fork(); 
    if (pid >0){
        pid_t pid_acabado; 
         pid_acabado = wait(&estado);
         printf("Soy el proceso padre, mi proceso hijo ha terminado"); 
         printf ("Y yo ahora espero 10 segundos antes de terminar"); 
         printf ("pid_acabado :  %d\n", pid_acabado); 
         sleep(20); 
    }

    else if (pid == 0){ // termina el hijo sin avisar al padre
        printf("PID del hijo: %d\n ", getpid()); 
        sleep(5); 
        exit(0); 
    } 
    else{
        perror("fork"); 
        exit(EXIT_FAIURE); 

    }
    return EXIT_SUCCESS;

}