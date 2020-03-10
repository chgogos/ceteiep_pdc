// Χειρισμός του race condition με mutex

#include <stdio.h>
#include <pthread.h>

#define T 10

int counter = 0;
pthread_mutex_t mutex;

void *work(void *id)
{
    long tid = (long)id;
    printf("Thread %ld started\n", tid);
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        if (i % 2 == 0)
            counter++;
        else
            counter--;
        pthread_mutex_unlock(&mutex);
    }
    printf("Thread %ld finished\n", tid);
    return NULL;
}

int main()
{
    pthread_t thread_handles[T];
    pthread_mutex_init(&mutex, NULL);
    for (long tid = 0; tid < T; tid++)
    {
        pthread_create(&thread_handles[tid], NULL, work, (void *)tid);
    }
    for (int i = 0; i < T; i++)
    {
        pthread_join(thread_handles[i], NULL);
    }
    printf("counter = %d\n", counter);
    pthread_mutex_destroy(&mutex);
}
