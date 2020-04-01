// για Τ = 10 νήματα
// φάση 1 (κάθε νήμα προσθέτει 1 στο total): 1 + 1 + ... + 1 = 10
// barrier
// φάση 2 (κάθε νήμα πολλαπλασιάζει το total επί 2): 10 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 = 10240
// ΔΕΝ ΛΕΙΤΟΥΡΓΕΙ ΣΩΣΤΑ ΔΙΟΤΙ ΔΕΝ ΥΠΑΡΧΕΙ BARRIER ΑΝΑΜΕΣΑ ΣΤΙΣ ΔΥΟ ΦΑΣΕΙΣ

#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define T 10

pthread_mutex_t lock;

int total = 0;

void *work(void *id)
{
    // ΦΑΣΗ 1
    pthread_mutex_lock(&lock);
    total++;
    pthread_mutex_unlock(&lock);

    // εδώ πρέπει να υπάρχει ένα barrier έτσι ώστε όλα τα νήματα να φτάσουν εδώ
    // και να περιμένουν την ολοκλήρωση της 1ης φάσης για τα άλλα threads

    // ΦΑΣΗ 2
    pthread_mutex_lock(&lock);
    total *= 2;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_mutex_init(&lock, NULL);

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

    pthread_mutex_destroy(&lock);
}
