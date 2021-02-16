// to be deleted

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int my_rank, comm_sz;
  int a = 0, sum, prod, max, min;

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

  srand(time(NULL) * my_rank);
  a = rand() % 100 + 1;
  printf("Process %d produced value %d\n", my_rank, a);
  
  MPI_Reduce(&a, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  MPI_Reduce(&a, &prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
  MPI_Reduce(&a, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
  MPI_Reduce(&a, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

  if (my_rank == 0) {
    printf("The sum is %d (for process 0)\n", sum);
    printf("The product is %d (for process 0)\n", prod);
    printf("The max is %d (for process 0)\n", max);
    printf("The min is %d (for process 0)\n", min);
  }

  MPI_Finalize();
  return 0;
}

/*
$ mpicc mpi_example05b.c
$ mpiexec -n 4 ./a.out
Process 2 produced value 55
Process 1 produced value 82
Process 3 produced value 28
Process 0 produced value 84
The sum is 249 (for process 0)
The product is 10607520 (for process 0)
The max is 84 (for process 0)
The min is 28 (for process 0)
*/