#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int max;
    sscanf(argv[1], "%d", &max);
#pragma omp parallel for
    for (int i = 1; i <= max; i++)
    #pragma omp parallel for
        for (int j = 1; j <= max; j++)
            printf("Thread%d: Pair(%d,%d)\n", omp_get_thread_num(), i, j);

    return 0;
}

/*
$ gcc listing3_7.c -o listing3_7.exe -fopenmp
$ listing3_7.exe 4
##############################################
CPU: Intel Core i7-7700K @ 4.2GHz  (4C/8T)
RAM: 32GB DDR4
----------------------------------------------
Windows 10
##############################################
Thread0: Pair(3,1)
Thread0: Pair(3,2)
Thread0: Pair(3,3)
Thread0: Pair(3,4)
Thread0: Pair(2,1)
Thread0: Pair(2,2)
Thread0: Pair(2,3)
Thread0: Pair(2,4)
Thread0: Pair(1,1)
Thread0: Pair(1,2)
Thread0: Pair(1,3)
Thread0: Pair(1,4)
Thread0: Pair(4,1)
Thread0: Pair(4,2)
Thread0: Pair(4,3)
Thread0: Pair(4,4)
*/