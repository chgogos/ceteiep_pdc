#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// άνω όριο για τους τυχαίους πραγματικούς αριθμούς που θα παραχθούν
#define a 10.0

/*
 Πίνακας Α με διαστάσεις m x n
 Διάνυσμα x με n στοιχεία
 Πολλαπλασιασμός του πίνακα Α με το διάνυσμα x χρησιμοποιώντας posix threads

 gcc -Wall -pthread pthreads_example02b.c -o pthreads_example02b
 ./pthreads_example02b 100000 1000 4
*/

// global variables
double **A;
double *x, *y;
int m, n, thread_count;

void generate_random_data(double **A, double *x, int m, int n) {
  srand(time(NULL));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      A[i][j] = a * (double)rand() / (double)RAND_MAX;

  for (int i = 0; i < n; i++)
    x[i] = a * (double)rand() / (double)RAND_MAX;
}

void *Pth_mat_vect(void *rank) {
  long my_rank = (long)rank;
  int i, j;
  int local_m = m / thread_count;
  int my_first_row = my_rank * local_m;
  int my_last_row = (my_rank + 1) * local_m - 1;

  for (i = my_first_row; i <= my_last_row; i++) {
    y[i] = 0.0;
    for (j = 0; j < n; j++)
      y[i] += A[i][j] * x[j];
  }
  return NULL;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    printf("Usage: %s m n t\n", argv[0]);
    printf("m = # of rows, n= # of columns, t = # of threads\n");
    exit(-1);
  }
  long thread_id;
  pthread_t *thread_handles;
  m = atoi(argv[1]);
  n = atoi(argv[2]);
  thread_count = atoi(argv[3]);

  x = (double *)malloc(sizeof(double) * n);
  A = (double **)malloc(sizeof(double *) * m);
  for (int i = 0; i < m; i++)
    A[i] = (double *)malloc(sizeof(double) * n);
  y = (double *)malloc(sizeof(double) * m);

  generate_random_data(A, x, m, n);

  thread_handles = malloc(sizeof(pthread_t) * thread_count);

  for (thread_id = 0; thread_id < thread_count; thread_id++)
    pthread_create(&thread_handles[thread_id], NULL, Pth_mat_vect,
                   (void *)thread_id);

  for (thread_id = 0; thread_id < thread_count; thread_id++)
    pthread_join(thread_handles[thread_id], NULL);

  // εκτύπωση των 10 πρώτων αποτελεσμάτων
  int k = m;
  if (k > 10)
    k = 10;
  for (int i = 0; i < k; i++)
    printf("%d -> %.2f\n", i, y[i]);

  free(x);
  free(y);
  for (int i = 0; i < m; i++)
    free(A[i]);
  free(A);
  return 0;
}