/**
 * //Compilación: gcc -Wall -std=c17 -pthread -o demo_threads demo_threads.c
//En otro terminal: ps -efL | grep demo_threads
 */

 #include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMERO_HILOS  2
#define MAXIMO_CONTADOR 10000000L

long int counter = 0;

void *f_counter(void *arg) {
    long id = *(long*) arg;
    printf("Iniciando %ld\n", id);

    long int max = MAXIMO_CONTADOR / NUMERO_HILOS;
    long int i;

    for (i = 0; i < max; i++) {
        counter++;   // SIN protección → condición de carrera
    }

    printf("Finalizado %ld. Contador: %ld\n", id, counter);
    sleep(2);
    printf("Finalizado %ld\n", id);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUMERO_HILOS];
    int rc;
    long t;
    long id[NUMERO_HILOS];

    for (t = 0; t < NUMERO_HILOS; t++) {
        id[t] = t;
        rc = pthread_create(&threads[t], NULL, f_counter, (void*)&id[t]);
        if (rc) {
            printf("Error: %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUMERO_HILOS; t++) {
        pthread_join(threads[t], NULL);
    }

    float error = (MAXIMO_CONTADOR - counter) / (float)MAXIMO_CONTADOR * 100;
    printf("Valor contador: %ld. Esperado: %ld. Error: %3.2f%%\n",
           counter, MAXIMO_CONTADOR, error);

    return 0;
}
