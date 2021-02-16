#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {
  int my_rank, comm_sz, dest;
  int a, sum;

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  if (my_rank == 0) {
    sum = 0;
    for (dest = 1; dest < comm_sz; dest++) {
      MPI_Recv(&a, 1, MPI_INT, dest, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      printf("Process 0 got value %d from process %d\n", a, dest);
      sum += a;
    }
    printf("The sum is %d\n", sum);
    fflush(stdout);
  } else {
    srand(time(NULL) * my_rank);
    int x = rand() % 100 + 1; 
    MPI_Send(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }
  MPI_Finalize();
  return 0;
}

/*
$ mpicc mpi_example02.c
$ mpiexec -n 4 ./a.out
Process 0 got value 44 from process 1
Process 0 got value 37 from process 2
Process 0 got value 23 from process 3
The sum is 104
*/