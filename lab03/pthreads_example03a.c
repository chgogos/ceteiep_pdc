// Pacheco example 4.3
// gcc -g -Wall lab6_02a.c -o lab6_02a
// the value of pi computed by the parallel code is not computed correctly
// due to race conditions

#include <stdio.h>
#include <pthread.h>

#define T 10      // number of threads
#define N 1000000 // number of terms of the series to use

// shared variable
double sum;

void *compute_pi_parallel(void *rank);
double compute_pi_serial(int);

int main() {
  long thread;
  pthread_t thread_handles[T];

  sum = 0.0;
  for (thread = 0; thread < T; thread++) {
    pthread_create(&thread_handles[thread], NULL, compute_pi_parallel,
                   (void *)thread);
  }

  for (thread = 0; thread < T; thread++) {
    pthread_join(thread_handles[thread], NULL);
  }
  sum = 4 * sum;
  printf("Pi value computed using %d terms and %d threads  = %.12f\n", N, T,
         sum);
  printf("Pi value computed using %d terms and serial code = %.12f\n", N,
         compute_pi_serial(N));
  return 0;
}

void *compute_pi_parallel(void *rank) {
  long my_rank = (long)rank;
  double factor;
  long i;
  long my_n = N / T;
  long my_first_i = my_n * my_rank;
  long my_last_i = my_first_i + my_n;
  if (my_first_i % 2 == 0)
    factor = 1.0;
  else
    factor = -1.0;
  for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
    sum += factor / (2 * i + 1);
  }
  return NULL;
}

double compute_pi_serial(int n) {
  int i;
  double factor = 1.0;
  double sum = 0.0;
  for (i = 0; i < n; i++, factor = -factor) {
    sum += factor / (2 * i + 1);
  }
  return 4.0 * sum;
}
