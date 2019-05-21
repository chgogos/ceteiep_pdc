#include <stdio.h>
#include <omp.h>

long fib(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n = 45;
#pragma omp parallel
    {
        int t = omp_get_thread_num();
        printf("%d: %ld\n", t, fib(n + t));
    }
    return 0;
}