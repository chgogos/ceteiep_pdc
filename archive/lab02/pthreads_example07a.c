// Για Τ νήματα, θέλουμε το νήμα 0 να στέλνει μήνυμα στο νήμα 1, το νήμα 1 στο 2 κ.ο.κ
// μέχρι το νήμα Τ-1 που υα στέλνει μήνυμα στο νήμα 0.
// Δεν λειτουργεί σωστά διότι δεν υπάρχει συγχρονισμός των νημάτων.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define T 10
#define MSG_MAX 100

char *messages[T];

void *Send_msg(void *rank)
{
    long my_rank = (long)rank;
    long dest = (my_rank + 1) % T;
    long source = (my_rank + T - 1) % T;
    char *my_msg = (char *)malloc(MSG_MAX * sizeof(char));

    sprintf(my_msg, "Hello to %ld from %ld", dest, my_rank);
    messages[dest] = my_msg;

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
        pthread_create(&threads[tid], NULL, Send_msg, (void *)tid);

    for (long tid = 0; tid < T; tid++)
        pthread_join(threads[tid], NULL);

    for (long tid = 0; tid < T; tid++)
        free(messages[tid]);
}

/* έξοδος
Thread 0 > No message from 9
Thread 3 > Hello to 3 from 2
Thread 8 > Hello to 8 from 7
Thread 6 > Hello to 6 from 5
Thread 7 > No message from 6
Thread 5 > No message from 4
Thread 2 > No message from 1
Thread 9 > Hello to 9 from 8
Thread 1 > Hello to 1 from 0
Thread 4 > Hello to 4 from 3
*/