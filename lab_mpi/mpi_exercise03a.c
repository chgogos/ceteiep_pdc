#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define N 1000

int main() {
  int comm_sz, my_rank;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  int stride = N / comm_sz;

  if (my_rank == 0) {
    int a[N], b[N];
    srand(1821);
    for (int i = 0; i < N; i++) {
      a[i] = rand() % 10 + 1;
      b[i] = rand() % 10 + 1;
    }
    // αποστολή τμημάτων του πίνακα στις διεργασίες
    for (int dest = 1; dest < comm_sz; dest++) {
      MPI_Send(a + dest * stride, stride, MPI_INT, dest, 0, MPI_COMM_WORLD);
      MPI_Send(b + dest * stride, stride, MPI_INT, dest, 0, MPI_COMM_WORLD);
    }
    int sum = 0;
    for (int i = 0; i < stride; i++)
      sum += a[i] * b[i];
    printf("Partial result from process 0 is %d\n", sum);
    // λήψη όλων των μερικών αποτελεσμάτων από τις διεργασίες 1..comm_sz-1
    for (int dest = 1; dest < comm_sz; dest++) {
      int partial_sum;
      MPI_Recv(&partial_sum, 1, MPI_INT, dest, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);
      sum += partial_sum;
    }
    printf("Sum %d\n", sum);
  } else {
    // λήψη τμημάτων του πίνακα από την διεργασία 0
    int a[stride], b[stride];
    MPI_Recv(&a, stride, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&b, stride, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // υπολογισμός μερικού αποτελέσματος και αποστολή στη διεργασία 0
    int sum = 0;
    for (int i = 0; i < stride; i++)
      sum += a[i] * b[i];
    MPI_Send(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    printf("Partial result from process %d is %d\n", my_rank, sum);
  }

  MPI_Finalize();
  return 0;
}
