#include <stdio.h>
#include <pthread.h>

#define T 2
#define M 6
#define N 2

int A[M][N] = {
    {1, 2},
    {3, 4},
    {5, 6},
    {7, 8},
    {9, 10},
    {11, 12}};

int x[N] = {10, 20};

// y = A * x
int y[] = {0, 0, 0, 0, 0, 0};

void *work(void *id)
{
    long tid = (long)id;
    int stride = M / T;
    int my_first_i = tid * stride;
    int my_last_i = (tid + 1) * stride;
    for (int i = my_first_i; i < my_last_i; i++)
    {
        y[i] = 0;
        for (int j = 0; j < N; j++)
            y[i] += A[i][j] * x[j];
    }
    return NULL;
}

int main()
{
    pthread_t thread_handles[T];
    for (long tid = 0; tid < T; tid++)
        pthread_create(&thread_handles[tid], NULL, work, (void *)tid);

    for (long tid = 0; tid < T; tid++)
        pthread_join(thread_handles[tid], NULL);

    for (int i = 0; i < M; i++)
        printf("y[%d]=%d\n", i, y[i]);
}