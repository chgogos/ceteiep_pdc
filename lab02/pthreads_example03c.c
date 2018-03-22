// the value of pi computed by the parallel code is correct because race
// conditions are handled by a mutex

#include <stdio.h>
#include <pthread.h>

#define T 10      // number of threads
#define N 1000000 // 10^6, number of terms of the series to use

// shared variables
double sum;
pthread_mutex_t mutex;

void *compute_pi_parallel(void *rank);

int main() {
  long thread;
  pthread_t thread_handles[T];
  pthread_mutex_init(&mutex, NULL);

  sum = 0.0;
  for (thread = 0; thread < T; thread++) {
    pthread_create(&thread_handles[thread], NULL, compute_pi_parallel,
                   (void *)thread);
  }

  for (thread = 0; thread < T; thread++) {
    pthread_join(thread_handles[thread], NULL);
  }
  sum = 4 * sum;
  printf("Pi value computed using %d terms and %d threads (mutex) = %.12f\n", N,
         T, sum);
  pthread_mutex_destroy(&mutex);
  return 0;
}

void *compute_pi_parallel(void *rank) {
  long my_rank = (long)rank;
  double factor;
  long i;
  long my_n = N / T;
  long my_first_i = my_n * my_rank;
  long my_last_i = my_first_i + my_n;
  double my_sum = 0.0;

  if (my_first_i % 2 == 0)
    factor = 1.0;
  else
    factor = -1.0;
  for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
    my_sum += factor / (2 * i + 1);
  }
  pthread_mutex_lock(&mutex);
  sum += my_sum;
  pthread_mutex_unlock(&mutex);
  return NULL;
}