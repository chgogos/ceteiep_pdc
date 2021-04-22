#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
  int my_rank, comm_sz;
  int sum, a = 0;

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

  srand(time(NULL) * my_rank);
  a = rand() % 100 + 1;
  printf("Process %d produced value %d\n", my_rank, a);

  MPI_Allreduce(&a, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
  printf("Process %d knows that the sum is %d\n", my_rank, sum);

  MPI_Finalize();
  return 0;
}

/*
$ mpicc mpi_example06.c
$ mpiexec -n 4 ./a.out
Process 0 produced value 84
Process 3 produced value 19
Process 1 produced value 33
Process 2 produced value 26
Process 0 knows that the sum is 162
Process 1 knows that the sum is 162
Process 2 knows that the sum is 162
Process 3 knows that the sum is 162
*/