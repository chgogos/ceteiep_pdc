#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define T 4

int A[N];
int B[N];
int sum = 0;
pthread_mutex_t mx;

void *thread_work(void *rank) {
  long myrank = (long)rank;
  int q = 0;
  for (int i = myrank * N / T; i < (myrank + 1) * N / T; i++)
    q += A[i] * B[i];
  pthread_mutex_lock(&mx);
  sum += q;
  pthread_mutex_unlock(&mx);
  return NULL;
}

int main() {
  srand(1821);
  for (int i = 0; i < N; i++) {
    A[i] = rand() % 10 + 1;
    B[i] = rand() % 10 + 1;
  }
  int q = 0;
  for (int i = 0; i < N; i++)
    q += A[i] * B[i];
  printf("dot product (serial)=%d\n", q);

  pthread_t threads[T];
  pthread_mutex_init(&mx, NULL);
  for (long i = 0; i < T; i++)
    pthread_create(&threads[i], NULL, thread_work, (void *)i);

  for (int i = 0; i < T; i++)
    pthread_join(threads[i], NULL);
  printf("dot product (parallel)=%d\n", sum);
  pthread_mutex_destroy(&mx);
  return 0;
}
