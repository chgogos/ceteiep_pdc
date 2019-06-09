#include <stdio.h>
#include <mpi.h>

int main()
{
    int comm_sz, my_rank;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int a[] = {50, 45, 33, 17, 19, 28};
    int partial_sum = 0;
    int total_sum;

    if (my_rank != 0)
    {
        for (int i = 1; i <= a[my_rank - 1]; i++)
        {
            partial_sum += i;
        }
        printf("Process %d computed %d\n", my_rank, partial_sum);
    }
    MPI_Reduce(&partial_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (my_rank == 0)
    {
        printf("The total sum is %d\n", total_sum);
    }

    MPI_Finalize();
    return 0;
}