#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define N 10

int main(int argc, char *argv[]) {
  int *a = NULL;
  int my_rank, comm_sz;
  int i;
  int *local_a;
  int local_n;

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  local_n = N / comm_sz;
  local_a = malloc(sizeof(int) * local_n);

  if (my_rank == 0) {
    srand(time(NULL));
    a = malloc(sizeof(int) * N);
    for (i = 0; i < N; i++) {
      a[i] = rand() % 10 + 1;
      printf("a[%d]=%d ", i, a[i]);
    }
    printf("\n");
    MPI_Scatter(a, local_n, MPI_INT, local_a, local_n, MPI_INT, 0,
                MPI_COMM_WORLD);
    free(a);
  } else {
    MPI_Scatter(a, local_n, MPI_INT, local_a, local_n, MPI_INT, 0,
                MPI_COMM_WORLD);
  }
  printf("Process %d ", my_rank);
  for (i = 0; i < local_n; i++)
    printf("%d ", local_a[i]);
  printf("\n");

  for (i = 0; i < local_n; i++)
    local_a[i] = local_a[i] * 2;

  if (my_rank == 0) {
    a = malloc(N * sizeof(int));
    MPI_Gather(local_a, local_n, MPI_INT, a, local_n, MPI_INT, 0,
               MPI_COMM_WORLD);
    printf("Result after gather ");
    for (int i = 0; i < N; i++)
      printf("a[%d]=%d ", i, a[i]);
    printf("\n");
  } else {
    MPI_Gather(local_a, local_n, MPI_INT, a, local_n, MPI_INT, 0,
               MPI_COMM_WORLD);
  }
  MPI_Finalize();
  return 0;
}