//Compilación: gcc -Wall -std=c17 -pthread -o demo_threads_SC demo_threads_SC.c
//Para ver los hilos que se generan, ejecutar en otro terminal: 
//ps -efL | grep demo_threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NUMERO_HILOS 10
#define MAXIMO_CONTADOR 10000000L

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long int counter = 0;

void *f_counter(void *arg){
    long id = *(long*) arg;
    printf("Iniciando %ld\n", id);

    // DEMO opcional: escribir en la pila del hilo principal
    long *pid = (long*) arg;
    printf("Iniciando %ld\n", *pid);

    long int i, max = MAXIMO_CONTADOR / NUMERO_HILOS;

    for (i = 0; i < max; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }

    printf("Fin %ld. Contador: %ld\n", id, counter);

    // DEMO opcional: modificar la pila del hilo principal
    sleep(1);
    *pid = *pid + 100;
    printf("Finalizado %ld\n", *pid);

    pthread_exit(NULL);
}

int main (int argc, char* argv[]){
    pthread_t threads[NUMERO_HILOS];
    int rc;
    long t;
    long id[NUMERO_HILOS];

    for (t = 0; t < NUMERO_HILOS; t++){
        id[t] = t;
        rc = pthread_create(&threads[t], NULL, f_counter, (void*) &id[t]);
        if (rc){
            printf("Error: %d\n", rc);
            exit(-1);
        }
    }

    for(t = 0; t < NUMERO_HILOS; t++){
        pthread_join(threads[t], NULL);
        //printf("ID %ld -> %ld\n", t, id[t]);
    }

    float error = (MAXIMO_CONTADOR - counter) / (float)MAXIMO_CONTADOR * 100;
    printf("Valor contador: %ld. Esperado: %ld. Error: %3.2f%%\n",
           counter, MAXIMO_CONTADOR, error);
}
