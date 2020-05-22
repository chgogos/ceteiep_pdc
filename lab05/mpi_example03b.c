#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int my_rank, comm_sz, dest;
  double a;
  int b;

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  float pi;
  if (my_rank == 0) {
    pi = 3.14f;
  }
  MPI_Bcast(&pi, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

  if (my_rank != 0) {
    printf("Process %d got value %lf\n", my_rank, pi);
  }
  MPI_Finalize();
  return 0;
}
