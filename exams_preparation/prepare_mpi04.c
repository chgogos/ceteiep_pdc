#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#define N 10

int main(void)
{
  int comm_sz, my_rank;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int local_n = N / comm_sz;
  int local_a[local_n];
  MPI_Scatter(a, local_n, MPI_INT, local_a, local_n, MPI_INT, 0, MPI_COMM_WORLD);

  if (my_rank == 0)
  {
    for (int i = 0; i < local_n; i++)
    {
      printf("%d", local_a[i]);
    }
  }

  MPI_Finalize();
  return 0;
}

/*
$ mpicc prepare_mpi04.c
$ mpirun -n 2 ./a.out
12345
$ mpirun -n 5 ./a.out
12
*/