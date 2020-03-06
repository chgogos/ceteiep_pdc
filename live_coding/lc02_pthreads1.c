#include <assert.h>
#include <pthread.h>
#include <stdio.h>

#define N 10000
#define T 2

int a[T];

void *work(void *id)
{
    long t_id = (long)id;

    int sum = 0;
    for (long i = t_id * N / T + 1; i <= (t_id + 1) * N / T; i++)
    {
        sum += i;
    }
    printf("Process %ld computes sum = %d\n", t_id, sum);
    a[t_id] = sum;
    return NULL;
}

int main()
{
    assert(N % T == 0);
    pthread_t t[T];
    for (long i = 0; i < T; i++)
    {
        pthread_create(&t[i], NULL, work, (void *)i);
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