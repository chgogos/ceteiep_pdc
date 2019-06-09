#include <stdio.h>
#include <mpi.h>

int main(void)
{
    int comm_sz, my_rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    printf("Process=%d, number of processes=%d\n", my_rank, comm_sz);

    MPI_Finalize();
    return 0;
}
