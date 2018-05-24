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

  MPI_Bcast(a, N, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(b, N, MPI_INT, 0, MPI_COMM_WORLD);

  int sum;
  int partial_sum = 0;
  for (int i = my_rank * stride; i < (my_rank + 1) * stride; i++)
    partial_sum += a[i] * b[i];
  printf("Partial result from process %d is %d\n", my_rank, partial_sum);
  MPI_Reduce(&partial_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  if (my_rank == 0) {
    printf("Sum %d\n", sum);
  }

  MPI_Finalize();
  return 0;
}