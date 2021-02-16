#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define N 1000

int main() {
  int comm_sz, my_rank;
  int a[N], b[N];

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  int stride = N / comm_sz;
  if (my_rank == 0) {
    srand(1821);
    for (int i = 0; i < N; i++) {
      a[i] = rand() % 10 + 1;
      b[i] = rand() % 10 + 1;
    }
  }
  int *local_a = malloc(sizeof(int) * stride);
  int *local_b = malloc(sizeof(int) * stride);
  MPI_Scatter(a, stride, MPI_INT, local_a, stride, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Scatter(b, stride, MPI_INT, local_b, stride, MPI_INT, 0, MPI_COMM_WORLD);

  int sum;
  int partial_sum = 0;
  for (int i = 0; i < stride; i++)
    partial_sum += local_a[i] * local_b[i];
  printf("Partial result from process %d is %d\n", my_rank, partial_sum);
  MPI_Reduce(&partial_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  if (my_rank == 0) {
    printf("Sum %d\n", sum);
  }

  MPI_Finalize();
  return 0;
}