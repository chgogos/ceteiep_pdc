#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000

int T;
int TOTAL =0;
pthread_mutex_t mutex;

void *work(void *id)
{
    long t_id = (long)id;

    int sum = 0;
    for (long i = t_id * N / T + 1; i <= (t_id + 1) * N / T; i++)
    {
        sum += i;
    }
    printf("Process %ld computes sum =%d\n", t_id, sum);
    pthread_mutex_lock(&mutex);
    TOTAL += sum;
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main(int argc, char *argv[])
{
    T = atoi(argv[1]);
    assert(N % T == 0);
    pthread_mutex_init(&mutex, NULL);
    pthread_t* t = malloc(sizeof(pthread_t)* T);
    for (long i = 0; i < T; i++)
    {
        pthread_create(&t[i], NULL, work, (void *)i);
    }

    for (int i = 0; i < T; i++)
    {
        pthread_join(t[i], NULL);
    }

    printf("%d\n", TOTAL);
    free(t);
    pthread_mutex_destroy(&mutex);
}