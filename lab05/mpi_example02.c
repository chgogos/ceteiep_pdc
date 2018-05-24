#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
  int my_rank, comm_sz, dest;
  double a;
  int b;

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  if (my_rank == 0) {
    printf("Enter 2 values (double and int): ");
    scanf("%lf %d", &a, &b);
    for (dest = 1; dest < comm_sz; dest++) {
      MPI_Send(&a, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD);
      MPI_Send(&b, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
    }
  } else {
    MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&b, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process %d got value %lf and value %d\n", my_rank, a, b);
  }
  MPI_Finalize();
  return 0;
}