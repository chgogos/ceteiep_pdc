#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main(void) {
  int comm_sz, my_rank;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  srand(time(NULL) * my_rank);
  int x = rand() % 100 + 1;
  printf("Process %d value %d\n", my_rank, x);

  MPI_Finalize();
  return 0;
}
