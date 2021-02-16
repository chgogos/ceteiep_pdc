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

/*
Hello:  1 2 0 5 7 4 3 6
*/