//Compilación: gcc -pthread -o counter counter.c

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define NUMERO_HILOS 2 
#define MAXIMO_CONTADOR 10000000

struct tdata 
{
    int tid;
};

int counter = 0; 
void *counter(void *ptr){
    long i , max = MAXIMO_CONTADOR/NUMERO_HILOS; 
    int tid = ((struct tdata *) ptr)->tid;
    for(i = 0; i<max;i++){
        counter +=1; // restricción de instrucciones 
    }
    printf("End %d contador: %d\n",tid,counter);
}

int main (int argc, char * argv[]){
    pthread_t threads[NUMERO_HILOS];
    int rc,i; 
    struct tdata id[NUMERO_HILOS]; 
    for(i = 0; i <NUMERO_HILOS;i++){
        id[i].tid =i;
        rc = pthread_create(&threads[i],NULL,count,(void *) &id[i]);
    }

    for (i = 0; <NUMERO_HILOS;i++){
        pthread_join(threads[i],NULL);
    }

    printf("Valor del contador: %d Exceso: %d\n",counter,MAXIMO_CONTADOR); 
    return 0; 
}
