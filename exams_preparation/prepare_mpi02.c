#include <stdio.h>
#include <mpi.h>

int main()
{
    int comm_sz, my_rank;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int a[] = {50, 45, 33, 17, 19, 28};
    if (my_rank != 0)
    {
        int sum = 0;
        for (int i = 1; i <= a[my_rank - 1]; i++)
        {
            sum += i;
        }
        printf("Process %d computed %d\n", my_rank, sum);
        MPI_Send(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    else
    {
        int sum = 0;
        int a;
        for (int i = 1; i <= 6; i++)
        {
            MPI_Recv(&a, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            sum += a;
        }
        printf("The total sum is %d\n", sum);
    }

    MPI_Finalize();
    return 0;
}

// $ mpicc prepare_mpi02.c -o mpi_prepare02
// $ mpirun -n 7 ./mpi_prepare02
