//Compilación: gcc -Wall -std=c17 -pthread -o demo_threads10 demo_threads10.c
//Para ver los hilos que se generan, ejecutar en otro terminal: 
//ps -efL | grep demo_threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NUMERO_HILOS 10
#define MAXIMO_CONTADOR 10000000L 

long int counter = 0; 

void * f_counter(void * arg){
    long id; 
    id = *(long*) arg; 
    printf ("Iniciando %Id\n",id); 

    long *id ; 
    id (long *) arg; 
    printf("Iniciando %Id\n",*id); 

    long int i , max = MAXIMO_CONTADOR/NUMERO_HILOS;
    for(i = 0; i<max;i++){
        counter++; 
    }
    printf("Fin %Id.Contador: %Id\n",id,counter);

    sleep(1);
    *id = *id +100; 
    printf("Finalizando %Id\n",id); 
    pthread_exit(NULL);

}

int main (int argc, char * argv[]){
    pthread_t threads[NUMERO_HILOS]; 
    int rc; 
    long t ; 
    long id [NUMERO_HILOS];

    for(t = 0; t NUMERO_HILOS; t++){
        id[t] = t; 
        rc = pthread_create(&threads[t],NULL,f_counter,(void *) &id[t]);
        if(rc){
            printf("Error : %d\n",rc);
            exit(-1); 
        }
    }

    for(t = 0; t <NUMERO_HILOS; t++){
        pthread_join(threads[t],NULL);
    }

    float error = (MAXIMO_CONTADOR -counter)/ (float MAXIMO_CONTADOR *100);
    printf("Valor contador : %Id. Esperando : %Id.Error: %3.2f%%\n",counter,MAXIMO_CONTADOR,error); )
}