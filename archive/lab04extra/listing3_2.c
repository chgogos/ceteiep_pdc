#include <stdio.h>
#include <omp.h>

long long fib(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n = 42;
#pragma omp parallel
    {
        int t = omp_get_thread_num();
        printf("%d: %lld\n", t, fib(n + t));
    }
    return 0;
}

/*
##############################################
CPU: Intel Core i7-7700K @ 4.2GHz  (4C/8T)
RAM: 32GB DDR4
----------------------------------------------
Windows 10
##############################################
0: 267914296
1: 433494437
2: 701408733
3: 1134903170
4: 1836311903
5: 2971215073
6: 4807526976
7: 7778742049
*/