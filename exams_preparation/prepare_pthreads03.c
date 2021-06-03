#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T 10
#define N 10000
#define M 1000000

int a[N];
int temp[N];
void *core(void *tid)
{
    long mytid = (long)tid;
    for (int i = mytid * (N / T); i < (mytid + 1) * (N / T); i++)
    {
        int c = 0;
        for (int j = 0; j < N; j++)
            if (a[j] < a[i])
                c++;
            else if (a[j] == a[i] && j < i)
                c++;
        temp[c] = a[i];
    }
    return NULL;
}

int is_sorted(int a[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return 0;
    return 1;
}

int main()
{
    clock_t start, finish;
    srand(42);
    for (int i = 0; i < N; i++)
        a[i] = rand() % M;
    start = clock();
    pthread_t threads[T];
    for (long i = 0; i < T; i++)
        pthread_create(&threads[i], NULL, core, (void *)i);
    for (long i = 0; i < T; i++)
        pthread_join(threads[i], NULL);
    for (int i = 0; i < N; i++)
        a[i] = temp[i];
    finish = clock();
    printf("Time elapsed %.2f\n", (double)(finish - start) / CLOCKS_PER_SEC);
    printf(is_sorted(a, N) ? "parallel rank sort ok (pthreads)"
                           : "parallel rank sort not ok (pthreads)");
    printf("\n");
    return 0;
}
