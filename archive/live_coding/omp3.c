#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define T 4

int main()
{
    int A[N], B[N];
    // srand(time(NULL));
    srand(1821);
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 10 + 1;
        B[i] = rand() % 10 + 1;
    }

    int q = 0;
    #pragma omp parallel for num_threads(T) reduction(+:q)
    for(int i=0;i<N;i++)
        q += A[i]*B[i];
    
    printf("Inner product = %d\n", q);
}