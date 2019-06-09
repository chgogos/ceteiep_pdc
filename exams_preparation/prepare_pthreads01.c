#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000000
#define T 4

int a[N] = {23, 11, 18, 90, 16, 22, 34, 52, 19, 41, 88, 72};
int max_num[T];

void *maximum(void *tid)
{
    long mytid = (long)tid;
    int maxs = 0;

    for (int i = mytid * (N / T); i < (mytid + 1) * (N / T); i++)
    {
        if (a[i] > maxs)
            maxs = a[i];
    }
    max_num[mytid] = maxs;
}

int main()
{
    int maxs = 0;
    pthread_t threads[T];

    for (long i = 0; i < T; i++)
    {
        pthread_create(&threads[i], NULL,
                       maximum, (void *)i);
    }

    for (int i = 0; i < T; i++)
    {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < T; i++)
    {
        if (max_num[i] > maxs)
            maxs = max_num[i];
    }

    printf("Maximun Element is : %d\n", maxs);

    return 0;
}
