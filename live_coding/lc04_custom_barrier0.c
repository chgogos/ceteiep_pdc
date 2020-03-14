// Υλοποίηση φράγματος με mutex και αναμονή σε εκρήγορση
// Μειονεκτήματα:
// 1) σπατάλη κύκλων ρολογιού της CPU λόγω του βρόχου αναμονής σε εκρήγορση (busy wait)
// 2) Ανάγκη χρήσης διαφορετικής μεταβλητής μετρητή για κάθε φράγμα

#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // sleep
#include <stdlib.h> // srand, rand

#define T 10

int counter = 0;
pthread_mutex_t barrier_mutex;

void *work(void *id)
{

    long tid = (long)id;
    srand(time(NULL) * tid);
    int sleep_duration = rand() % 5 + 1;
    printf("Phase A. Thread %ld will sleep for %d seconds.\n", tid, sleep_duration);
    sleep(sleep_duration);
    pthread_mutex_lock(&barrier_mutex);
    counter++;
    pthread_mutex_unlock(&barrier_mutex);
    while (counter < T)
        ;
    printf("Phase B. Thread %ld woke up.\n", tid);
    return NULL;
}

int main()
{
    pthread_mutex_init(&barrier_mutex, NULL);

    pthread_t thread_handles[T];
    for (long tid = 0; tid < T; tid++)
    {
        pthread_create(&thread_handles[tid], NULL, work, (void *)tid);
    }

    for (int tid = 0; tid < T; tid++)
    {
        pthread_join(thread_handles[tid], NULL);
    }
    pthread_mutex_destroy(&barrier_mutex);
}