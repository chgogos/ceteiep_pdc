#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int max;
    sscanf(argv[1], "%d", &max);
#pragma omp parallel for schedule(static,1)
    for (int i = 1; i <= max; i++)
        printf("Thread%d: Value%d\n", omp_get_thread_num(), i);

    return 0;
}

/*
$ gcc-9 listing3_3.c -o listing3_3.exe -fopenmp
$ ./listing3_3 16
##############################################
CPU: Intel Core i7 @ 2.9 GHz           (2C/4T)
RAM: 8GB
----------------------------------------------
macOS Catalina
##############################################
Thread0: Value1
Thread0: Value5
Thread0: Value9
Thread0: Value13
Thread2: Value3
Thread2: Value7
Thread2: Value11
Thread2: Value15
Thread3: Value4
Thread3: Value8
Thread3: Value12
Thread3: Value16
Thread1: Value2
Thread1: Value6
Thread1: Value10
Thread1: Value14
*/
