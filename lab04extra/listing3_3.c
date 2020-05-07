#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int max;
    sscanf(argv[1], "%d", &max);
#pragma omp parallel for
    for (int i = 1; i <= max; i++)
        printf("Thread%d: Value%d\n", omp_get_thread_num(), i);

    return 0;
}

/*
$ gcc listing3_3.c -o listing3_3.exe -fopenmp
$ listing3_3.exe 16
##############################################
CPU: Intel Core i7-7700K @ 4.2GHz  (4C/8T)
RAM: 32GB DDR4
----------------------------------------------
Windows 10
##############################################
Thread7: Value15
Thread7: Value16
Thread4: Value9
Thread4: Value10
Thread0: Value1
Thread0: Value2
Thread3: Value7
Thread3: Value8
Thread5: Value11
Thread5: Value12
Thread2: Value5
Thread2: Value6
Thread1: Value3
Thread1: Value4
Thread6: Value13
Thread6: Value14
*/

/*
##############################################
CPU: Intel Core i7 @ 2.9 GHz           (2C/4T)
RAM: 8GB
----------------------------------------------
macOS Catalina
##############################################
Thread0: Value1
Thread0: Value2
Thread2: Value9
Thread2: Value10
Thread2: Value11
Thread2: Value12
Thread0: Value3
Thread0: Value4
Thread3: Value13
Thread3: Value14
Thread1: Value5
Thread1: Value6
Thread1: Value7
Thread1: Value8
Thread3: Value15
Thread3: Value16
*/
