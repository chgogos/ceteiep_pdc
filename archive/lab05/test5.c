#include <stdio.h>
#include <mpi.h>

int main()
{
    int comm_sz, my_rank;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int a[] = {7,13,2,8};
    if (my_rank != 0)
    {
        int max = 0;
        for (int i = my_rank - 1; i < 4; i++)
        {
            if (a[i]>max){
                max = a[i];
            }
        }
        MPI_Send(&max, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    else
    {
        int a;
        for (int i = 1; i <= 3; i++)
        {
            MPI_Recv(&a, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Maximum %d\n", a);
        }
    }

    MPI_Finalize();
    return 0;
}