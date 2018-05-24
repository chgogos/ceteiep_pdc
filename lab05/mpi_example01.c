#include <stdio.h>
#include <string.h>
#include <mpi.h>

#define MAX 100

int main(void) {
  char message[MAX];
  int comm_sz, my_rank;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  if (my_rank != 0) {
    sprintf(message, "Process %d of %d says hello.", my_rank, comm_sz);
    MPI_Send(message, strlen(message) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
  } else {
    printf("This is  process %d waiting for messages\n", my_rank);
    for (int q = 1; q < comm_sz; q++) {
      MPI_Recv(message, MAX, MPI_CHAR, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      printf("%s\n", message);
    }
  }

  MPI_Finalize();
  return 0;
}
