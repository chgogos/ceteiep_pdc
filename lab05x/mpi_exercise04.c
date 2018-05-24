#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mpi.h>

#define TOTAL_POINTS 300000000

int main(int argc, char *argv[]) {
  int my_rank, comm_sz, dest, total;

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  srand48(time(NULL) * my_rank);

  int points = TOTAL_POINTS / comm_sz;
  int c = 0;
  for (int i = 0; i < points; i++) {
    double x, y, d;
    x = drand48();
    y = drand48();
    x = x * 2 - 1;
    y = y * 2 - 1;
    d = sqrt(x * x + y * y);
    if (d < 1)
      c++;
  }

  MPI_Reduce(&c, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  double pi = (double)total / (double)TOTAL_POINTS * 4;
  if (my_rank == 0)
    printf("PI estimation %f\n", pi);

  MPI_Finalize();
  return 0;
}