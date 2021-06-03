#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(void)
{
  int comm_sz, my_rank;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  if (my_rank == 0 && comm_sz != 2)
  {
    printf("Number of processes should be 2.\n");
    exit(-1);
  }

  if (my_rank == 1)
  {
    int a = 42;
    MPI_Send(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }
  else
  {
    int a;
    MPI_Recv(&a, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("The answer to the universe is %d\n", a);
  }

  MPI_Finalize();
  return 0;
}


// $ mpicc prepare_mpi01.c -o mpi_prepare01
// $ mpirun -n 2 ./mpi_prepare01
