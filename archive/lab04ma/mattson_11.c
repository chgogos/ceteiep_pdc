#include <stdio.h>
#include <omp.h>

void main(){
    printf("Number of processors %d\n", omp_get_num_procs());
    omp_set_num_threads(100);
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        if (id==0)
            printf("Number of threads %d\n", omp_get_num_threads());
    }
}