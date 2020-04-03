// παραλλαγή της prepare_pthreads01.c με δημιουργία τυχαίων τιμών και πίνακα 100Κ

#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
#define T 4

typedef long long ll;

ll a[N];
ll max_num[T];

void *maximum(void *tid) {
  intptr_t mytid = (intptr_t)tid;
  ll maxs = 0;

  for (int i = mytid * (N / T); i < (mytid + 1) * (N / T); i++) {
    if (a[i] > maxs)
      maxs = a[i];
  }
  max_num[mytid] = maxs;
}

int main() {
  srand(time(NULL));
  for (ll i = 0; i < N; i++) {
    a[i] = (RAND_MAX + 1) * (ll)rand() +
           rand(); // get larger random number than RAND_MAX
  }

  pthread_t threads[T];

  for (intptr_t i = 0; i < T; i++) {
    pthread_create(&threads[i], NULL, maximum, (void *)i);
  }

  for (int i = 0; i < T; i++) {
    pthread_join(threads[i], NULL);
  }

  ll maxs = 0;
  for (int i = 0; i < T; i++) {
    if (max_num[i] > maxs)
      maxs = max_num[i];
  }

  printf("Maximun Element is : %lld\n", maxs);

  return 0;
}
