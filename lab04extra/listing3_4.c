// vector addition
// TBC

#include <omp.h>
#include <stdlib.h> // RAND_MAX
#include <stdio.h>
#include <time.h>

void vect_add(double *c, double *a, double *b, int n)
{
#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
    }
}

#define N 1000
int main()
{
    double a[N], b[N], c[N];
    srand(time(NULL));
    // srand(42);
    for (int i = 0; i < N; i++)
    {
        a[i] = (double)rand() / RAND_MAX * 100.0;
        b[i] = (double)rand() / RAND_MAX * 100.0;
    }
    vect_add(c, a, b, N);
    for (int i = 0; i < 5; i++)
    {
        printf("%.2f \n", c[i]);
    }
    return 0;
}