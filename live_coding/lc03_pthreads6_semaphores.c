// Χειρισμός του race condition με semaphore
// Δημιουργούνται 10 σημαφόροι, ένας ανά thread. 
// Αρχικά όλοι εκτός από τον semaphores[0] είναι κλειδωμένοι 0
// Μόλις ολοκληρώσει την εργασία του το νήμα tid ξεκλειδώνει το σημαφόρο semaphores[tid+1]

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define T 10

int counter = 0;
sem_t semaphores[T];

void *work(void *id)
{
    long tid = (long)id;
    sem_wait(&semaphores[tid]);
    printf("Thread %ld started\n", tid);
    for (int i = 0; i < 1000000; i++)
    {
        if (i % 2 == 0)
            counter++;
        else
            counter--;
    }
    if (tid != T - 1)
        sem_post(&semaphores[tid + 1]);    
    printf("Thread %ld finished\n", tid);
    return NULL;
}

int main()
{
    sem_init(&semaphores[0], 0, 1); // unlock semaphore 0
    for (int i = 1; i < T; i++)
        sem_init(&semaphores[i], 0, 0);

    pthread_t thread_handles[T];
    for (long tid = 0; tid < T; tid++)
    {
        pthread_create(&thread_handles[tid], NULL, work, (void *)tid);
    }
    for (int i = 0; i < T; i++)
    {
        pthread_join(thread_handles[i], NULL);
    }
    printf("counter = %d\n", counter);
    sem_destroy(semaphores);
}
