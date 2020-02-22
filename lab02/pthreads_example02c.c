#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// άνω όριο για τους τυχαίους πραγματικούς αριθμούς που θα παραχθούν
#define a 10.0

#define M 100000
#define N 8000

// αριθμός νημάτων
#define T 4

/*
 Πίνακας Α με διαστάσεις M x N
 Διάνυσμα x με N στοιχεία
 Πολλαπλασιασμός του πίνακα Α με το διάνυσμα x χρησιμοποιώντας posix threads

 gcc -Wall -pthread pthreads_example02c.c -o pthreads_example02c
 ./pthreads_example02c
*/

// global variables
double A[M][N];
double x[N], y[M];

void *Pth_mat_vect(void *rank)
{
  long my_rank = (long)rank;
  int i, j;
  int local_m = M / T;
  int my_first_row = my_rank * local_m;
  int my_last_row = (my_rank + 1) * local_m - 1;

  for (i = my_first_row; i <= my_last_row; i++)
  {
    y[i] = 0.0;
    for (j = 0; j < N; j++)
      y[i] += A[i][j] * x[j];
  }
  return NULL;
}

int main()
{
  srand(time(NULL));
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      A[i][j] = a * (double)rand() / (double)RAND_MAX;

  for (int i = 0; i < N; i++)
    x[i] = a * (double)rand() / (double)RAND_MAX;

  pthread_t thread_handles[T];

  for (long thread_id = 0; thread_id < T; thread_id++)
    pthread_create(&thread_handles[thread_id], NULL, Pth_mat_vect,
                   (void *)thread_id);

  for (long thread_id = 0; thread_id < T; thread_id++)
    pthread_join(thread_handles[thread_id], NULL);

  printf("y[%d] = %.2f\n", 0, y[0]);
  printf("...\n");
  printf("y[%d] = %.2f\n", M - 1, y[M - 1]);
  return 0;
}
