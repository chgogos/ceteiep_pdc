// Χειρισμός του race condition με busy wait
// Χρήση volatile μεταβλητής έτσι ώστε εαν η μεταγλώττιση γίνει με βελτιστοποίηση να λειτουργεί σωστά το busy wait

#include <stdio.h>
#include <pthread.h>

#define T 10

int counter = 0;

volatile int flag = 0;

void *work(void *id)
{
    long tid = (long)id;
    while (flag != tid)
        ;
    printf("Thread %ld started\n", tid);
    for (int i = 0; i < 1000000; i++)
    {
        if (i % 2 == 0)
            counter++;
        else
            counter--;
    }
    printf("Thread %ld finished\n", tid);
    flag++;
    return NULL;
}

int main()
{
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
}
