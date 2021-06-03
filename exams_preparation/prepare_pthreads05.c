// πολυνηματικός κώδικας για τον υπολογισμό του εσωτερικού γινομένου
// δύο τυχαίων διανυσμάτων με Ν τιμές το καθένα.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define N 1000000
#define T 5

double *a;
double *b;
double inner_prod = 0.0;
pthread_mutex_t mx;


void *thread_work(void *rank) {
  intptr_t myrank = (intptr_t)rank;
  double tmp = 0;
  for (int i = myrank * N / T; i < (myrank + 1) * N / T; i++)
    tmp += a[i] * b[i];
  pthread_mutex_lock(&mx);
  inner_prod += tmp;
  pthread_mutex_unlock(&mx);
  return NULL;
}

int main() {
  a = (double *)malloc(sizeof(double) * N);
  b = (double *)malloc(sizeof(double) * N);
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    a[i] = (double)rand() / (double)RAND_MAX;
    b[i] = (double)rand() / (double)RAND_MAX;
  }

  pthread_t threads[T];
  pthread_mutex_init(&mx, NULL);
  for (intptr_t i = 0; i < T; i++)
    pthread_create(&threads[i], NULL, thread_work, (void *)i);

  for (int i = 0; i < T; i++)
    pthread_join(threads[i], NULL);

  printf("%.2f\n", inner_prod);
  pthread_mutex_destroy(&mx);

  free(a);
  free(b);
}
