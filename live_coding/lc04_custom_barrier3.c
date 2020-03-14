// για Τ = 10 νήματα
// φάση 1 (κάθε νήμα προσθέτει 1 στο total): 1 + 1 + ... + 1 = 10
// barrier
// φάση 2 (κάθε νήμα πολλαπλασιάζει το total επί 2): 10 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 = 10240
// υλοποίηση barrier με conditional variable

#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define T 10

int counter = 0;
pthread_mutex_t lock1;
pthread_cond_t cond_var;
pthread_mutex_t lock2;
int total = 0;

void *work(void *id)
{
    // ΦΑΣΗ 1
    pthread_mutex_lock(&lock2);
    total++;
    pthread_mutex_unlock(&lock2);

    // BARRIER (START)
    pthread_mutex_lock(&lock1);
    counter++;
    if (counter == T)
    {
        counter = 0;
        pthread_cond_broadcast(&cond_var);
    }
    else
    {
        while (pthread_cond_wait(&cond_var, &lock1) != 0)
            ;
    }
    pthread_mutex_unlock(&lock1);
    // BARRIER (END)

    // ΦΑΣΗ 2
    pthread_mutex_lock(&lock2);
    total *= 2;
    pthread_mutex_unlock(&lock2);
    return NULL;
}

int main()
{
    pthread_cond_init(&cond_var, NULL);
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    pthread_t thread_handles[T];
    for (long tid = 0; tid < T; tid++)
    {
        pthread_create(&thread_handles[tid], NULL, work, (void *)tid);
    }

    for (int tid = 0; tid < T; tid++)
    {
        pthread_join(thread_handles[tid], NULL);
    }
    printf("Total = %d (expected total = %d)\n", total, (int)(T * pow(2, T)));

    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    pthread_cond_destroy(&cond_var);
}
