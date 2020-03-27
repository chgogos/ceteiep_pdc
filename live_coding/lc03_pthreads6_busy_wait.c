// Χειρισμός του race condition με busy wait
// Προσοχή: αν η μεταγλώττιση γίνει με προσθήκη flag βελτιστοποίησης π.χ.
// $ gcc lc03_pthreads6_busy_wait.c -O3
// τότε ενδέχεται να μην επιστρέφει σωστή τιμή ή να μην λειτουργεί

#include <stdio.h>
#include <pthread.h>

#define T 4

int counter = 0;

int flag = 0;
void *work(void *id)
{
    long tid = (long)id;
    printf("Thread %ld started\n", tid);
    for (int i = 0; i < 1000000; i++)
    {
        while (flag != tid)
            ;
        // κρίσιμο τμήμα (αρχή)
        if (i % 2 == 0)
            counter++;
        else
            counter--;
        // κρίσιμο τμήμα (τέλος)
        flag = (flag + 1) % T;
    }
    printf("Thread %ld finished\n", tid);
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
    printf("Counter = %d\n", counter);
}
