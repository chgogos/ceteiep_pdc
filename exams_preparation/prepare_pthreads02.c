// ΠΡΟΟΔΟΣ 27/4/2018 ΘΕΜΑ 2

#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define T 10      // πλήθος νημάτων
#define N 1000000 // πλήθος στοιχείων πίνακα
#define M 100     // εύρος τιμών

int a[N];
int frequency[M];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_counter(void *tid) {
  intptr_t mytid = (intptr_t)tid;
  int local_freq[M];
  for (int i = 0; i < M; i++) {
    local_freq[i] = 0;
  }
  for (int i = mytid * N / T; i < (mytid + 1) * N / T; i++) {
    local_freq[a[i]]++;
  }
  pthread_mutex_lock(&lock);
  for (int i = 0; i < M; i++) {
    frequency[i] += local_freq[i];
  }
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main() {
  srand(1729);
  for (int i = 0; i < N; i++) {
    a[i] = rand() % M;
  }

  pthread_t threads[T];
  for (intptr_t t = 0; t < T; t++) {
    pthread_create(&threads[t], NULL, thread_counter, (void *)t);
  }

  for (int t = 0; t < T; t++) {
    pthread_join(threads[t], NULL);
  }

  for (int i = 0; i < M; i++) {
    printf("%d -> %d\n", i, frequency[i]);
  }
}
