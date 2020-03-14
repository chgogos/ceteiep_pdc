#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // sleep
#include <stdlib.h> // srand, rand

#define T 10

int counter = 0;
pthread_mutex_t barrier_mutex = PTHREAD_MUTEX_INITIALIZER;

void *work(void *id)
{

    long tid = (long)id;
    srand(time(NULL) * tid);
    int sleep_duration = rand() % 10;
    printf("Thread %ld sleeps for %d seconds\n", tid, sleep_duration);
    sleep(sleep_duration);
    pthread_mutex_lock(&barrier_mutex);
    counter++;
    pthread_mutex_unlock(&barrier_mutex);
    printf("Thread %ld is waiting\n", tid);
    while (counter < T)
        ;
}

int main()
{
    pthread_t thread_handles[T];
    for (long tid = 0; tid < T; tid++)
    {
        thread_handles[tid] = pthread_create(&thread_handles[tid], NULL, work, (void *)tid);
    }

    for (int tid = 0; tid < T; tid++)
    {
        pthread_join(thread_handles[tid], NULL);
    }

}