#include <assert.h>
#include <pthread.h>
#include <stdio.h>

#define N 10000
#define T 2

int a[T];

void *work(void *id)
{
    int t_id = *((int *)id); // μετατροπή από void* σε int* και αποαναφορά

    int sum = 0;
    for (int i = t_id * N / T + 1; i <= (t_id + 1) * N / T; i++)
    {
        sum += i;
    }
    printf("Process %d computes sum = %d\n", t_id, sum);
    a[t_id] = sum;
    return NULL;
}

int main()
{
    assert(N % T == 0);
    pthread_t t[T];     // νήματα
    int threads_ids[T]; // αναγνωριστικά των νημάτων
    for (int i = 0; i < T; i++)
    {
        threads_ids[i] = i;
        pthread_create(&t[i], NULL, work, (void *)&threads_ids[i]);
    }

    for (int i = 0; i < T; i++)
    {
        pthread_join(t[i], NULL);
    }

    int sum = 0;
    for (int i = 0; i < T; i++)
        sum += a[i];
    printf("%d\n", sum);
}