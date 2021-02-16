#include <pthread.h>
#include <stdio.h>

#define N 10000

int a[2];
void *work1(void *id)
{
    int sum = 0;
    for (int i = 1; i <= N / 2; i++)
    {
        sum += i;
    }
    printf("Process %s computes sum = %d\n", (char*)id, sum);
    a[0] = sum;
    return NULL;
}

void *work2(void *id)
{
    int sum = 0;
    for (int i = N / 2 + 1; i <= N; i++)
    {
        sum += i;
    }
    printf("Process %s computes sum = %d\n", (char*)id, sum);
    a[1] = sum;
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, work1, "A");
    pthread_create(&t2, NULL, work2, "B");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("%d\n", a[0] + a[1]);
}
