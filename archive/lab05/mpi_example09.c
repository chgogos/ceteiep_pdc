// n σε πλήθος διεργασίες μοιράζονται N τιμές ενός πίνακα, η κάθε μια λαμβάνει Ν/n τιμές
// κάθε διεργασία υπολογίζει το άθροισμα των τιμών που λαμβάνει και το επιστρέφει 
// όλα τα αποτελέσματα συγκεντρώνονται από τη διεργασία 0 και εμφανίζονται

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 20

int main() {
  int a[N], *local_a;
  int my_rank, comm_sz, local_n;
  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  for (int i = 0; i < N; i++) {
    a[i] = i;
  }
  local_n = N / comm_sz;
  local_a = malloc(sizeof(int) * local_n);
  MPI_Scatter(a, local_n, MPI_INT, local_a, local_n, MPI_INT, 0,
              MPI_COMM_WORLD);
  for (int i = 0; i < local_n; i++)
    printf("MPI Process %d has value %d\n", my_rank, local_a[i]);

  int local_sum = 0;
  for (int i = 0; i < local_n; i++) {
    local_sum += local_a[i];
  }
  printf("MPI Process %d computed result %d\n", my_rank, local_sum);

  int *results = NULL;

  if (my_rank == 0) {
    results = malloc(comm_sz * sizeof(int));
    MPI_Gather(&local_sum, 1, MPI_INT, results, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("MPI Process %d: ", my_rank);
    for (int i = 0; i < comm_sz; i++)
      printf("results[%d]=%d ", i, results[i]);
    printf("\n");
  } else {
    MPI_Gather(&local_sum, 1, MPI_INT, results, 1, MPI_INT, 0, MPI_COMM_WORLD);
  }

  MPI_Finalize();
}

/*
$ mpicc mpi_example09.c
$ mpiexec -n 5 ./a.out
MPI Process 0 has value 0
MPI Process 0 has value 1
MPI Process 0 has value 2
MPI Process 0 has value 3
MPI Process 0 has value 4
MPI Process 0 computed result 10
MPI Process 1 has value 5
MPI Process 1 has value 6
MPI Process 1 has value 7
MPI Process 1 has value 8
MPI Process 1 has value 9
MPI Process 1 computed result 35
MPI Process 2 has value 10
MPI Process 2 has value 11
MPI Process 2 has value 12
MPI Process 2 has value 13
MPI Process 2 has value 14
MPI Process 2 computed result 60
MPI Process 3 has value 15
MPI Process 3 has value 16
MPI Process 3 has value 17
MPI Process 3 has value 18
MPI Process 3 has value 19
MPI Process 3 computed result 85
MPI Process 0: results[0]=10 results[1]=35 results[2]=60 results[3]=85
*/