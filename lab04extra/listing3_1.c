#include <stdio.h>
#include <omp.h>

int main()
{
    printf("Hello: ");
#pragma omp parallel
    printf(" %d", omp_get_thread_num());
    printf("\n");

    return 0;
}
