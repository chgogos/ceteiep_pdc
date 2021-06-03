#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define N 1000000

int main()
{
  double *a;
  double *b;
  double inner_prod = 0.0;
  a = (double *)malloc(sizeof(double) * N);
  b = (double *)malloc(sizeof(double) * N);
  srand(time(NULL));
  for (int i = 0; i < N; i++)
  {
    a[i] = (double)rand() / (double)RAND_MAX;
    b[i] = (double)rand() / (double)RAND_MAX;
  }

  // MPI SOLUTION (START)
  int comm_sz, my_rank;
  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  double inner_prod_local = 0;
  for (int i = my_rank * N / comm_sz; i < (my_rank + 1) * N / comm_sz; i++)
  {
    inner_prod_local += a[i] * b[i];
  }
  printf("Process %d computed %.2f\n", my_rank, inner_prod_local);
  MPI_Reduce(&inner_prod_local, &inner_prod, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  if (my_rank == 0)
  {
    printf("%.2f\n", inner_prod);
  }
  MPI_Finalize();
  // MPI SOLUTION (END)

  free(a);
  free(b);
}

/*
Process 3 computed 50100.58
Process 0 computed 50286.32
Process 1 computed 50178.91
Process 4 computed 50029.59
Process 2 computed 50014.18
250609.58
*/