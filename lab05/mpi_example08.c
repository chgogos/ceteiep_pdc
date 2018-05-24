#include <stdio.h>
#include <mpi.h>

/*
σελίδα 191: Παράλληλα συστήματα και Προγραμματισμός ΚΑΛΛΙΠΟΣ
*/
int main(int argc, char *argv[]) {
  int N, i, myid, nproc;
  MPI_Status status;
  double w, result = 0.0, temp;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &nproc);

  // initialization
  if (myid == 0) {
    printf("Enter number of divisions: ");
    scanf("%d", &N);
    for (i = 1; i < nproc; i++)
      MPI_Send(&N, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
  } else
    MPI_Recv(&N, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

  // computations
  w = 1.0 / N;
  for (i = myid; i < N; i += nproc)
    result += 4 * w / (1 + (i + 0.5) * (i + 0.5) * w * w);

  // gather results
  if (myid == 0) {
    for (i = 1; i < nproc; i++) {
      MPI_Recv(&temp, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, &status);
      // receives messages from any source
      // MPI_Recv(&temp, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD,
      // &status);
      result += temp;
    }
    printf("pi=%.14f\n", result);
  } else
    MPI_Send(&result, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);

  MPI_Finalize();
  return 0;
}