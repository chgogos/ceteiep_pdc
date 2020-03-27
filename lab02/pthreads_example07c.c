// Για Τ νήματα, θέλουμε το νήμα 0 να στέλνει μήνυμα στο νήμα 1, το νήμα 1 στο 2 κ.ο.κ
// μέχρι το νήμα Τ-1 που υα στέλνει μήνυμα στο νήμα 0.
// Συγχρονισμός των νημάτων με semaphores. Χρήση ενός semaphore ανά νήμα.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define T 10
#define MSG_MAX 100

char *messages[T];
sem_t semaphores[T];

void *Send_msg(void *rank)
{
    long my_rank = (long)rank;
    long dest = (my_rank + 1) % T;
    long source = (my_rank + T - 1) % T;
    char *my_msg = (char *)malloc(MSG_MAX * sizeof(char));

    sprintf(my_msg, "Hello to %ld from %ld", dest, my_rank);
    messages[dest] = my_msg;
    sem_post(&semaphores[dest]);

    sem_wait(&semaphores[my_rank]);
    if (messages[my_rank] != NULL)
        printf("Thread %ld > %s\n", my_rank, messages[my_rank]);
    else
        printf("Thread %ld > No message from %ld\n", my_rank, source);

    return NULL;
}

int main()
{
    pthread_t threads[T];
    for (long tid = 0; tid < T; tid++)
        messages[tid] = NULL;

    for (long tid = 0; tid < T; tid++)
        sem_init(&semaphores[tid], 0, 1);

    for (long tid = 0; tid < T; tid++)
        pthread_create(&threads[tid], NULL, Send_msg, (void *)tid);

    for (long tid = 0; tid < T; tid++)
        pthread_join(threads[tid], NULL);

    for (long tid = 0; tid < T; tid++)
        sem_destroy(&semaphores[tid]);

    for (long tid = 0; tid < T; tid++)
        free(messages[tid]);
}

/*
Thread 0 > No message from 9
Thread 1 > Hello to 1 from 0
Thread 2 > Hello to 2 from 1
Thread 4 > Hello to 4 from 3
Thread 5 > Hello to 5 from 4
Thread 6 > Hello to 6 from 5
Thread 7 > Hello to 7 from 6
Thread 8 > Hello to 8 from 7
Thread 3 > Hello to 3 from 2
^C
*/