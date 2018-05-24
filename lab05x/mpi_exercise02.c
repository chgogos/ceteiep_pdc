#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// mpirun -n 4 ./mpi_exercise02 10000000

int main(int argc, char *argv[]) {
  int comm_sz, my_rank;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  if (my_rank == 0 && argc != 2) {
    printf("Wrong number of arguments\n");
    printf("Should use: mpirun -n 4 %s 10000000\n", argv[0]);
    exit(-1);
  }

  long long N = atoll(argv[1]);
  long long sum = 0;
  long long stride = N / comm_sz;
  long long left = my_rank * stride + 1;
  long long right = (my_rank + 1) * stride;
  long long a = 0;
  for (long long i = left; i <= right; i++)
    a += i;
  MPI_Reduce(&a, &sum, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
  if (my_rank == 0)
    printf("The sum is %lld\n", sum);

  MPI_Finalize();
  return 0;
}
