/**
 * ejemplo de hijo zombie 
 */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    pid_t pid; 
    pid = fork(); 
    if(pid >0 ){ // es el proceso padre 
        printf("Soy el padre y estero 20 segundos, antes de terminar, no se nada de mi hijo"); 
        sleep(20);

    }else if (pid == 0 ){// proceso hijo termina sin notificar  al padre 
        exit(0);

    }

    else{
        perror("fork"); 
        exit(EXIT_FAIURE); 

    }
    return EXIT_SUCCESS;

}