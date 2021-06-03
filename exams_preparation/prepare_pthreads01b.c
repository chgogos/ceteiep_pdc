// παραλλαγή της prepare_pthreads01.c με δημιουργία τυχαίων τιμών και πίνακα
// 100Κ

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
  ll local_max = 0;

  for (int i = mytid * (N / T); i < (mytid + 1) * (N / T); i++) {
    if (a[i] > local_max)
      local_max = a[i];
  }
  max_num[mytid] = local_max;
  return NULL;
}

int main() {
  srand(time(NULL));
  for (ll i = 0; i < N; i++) {
    // (Windows + MinGW-W64 gcc 8.1.0): Καθώς το RAND_MAX είναι 32767 με την ακόλουθη εντολή λαμβάνουμε
    // τυχαίες τιμές μεγαλύτερες από RAND_MAX
    a[i] = (RAND_MAX + 1) * (ll)rand() + rand();
    
    // (Linux): 
    // a[i] = rand();
  }

  pthread_t threads[T];

  for (intptr_t i = 0; i < T; i++) {
    pthread_create(&threads[i], NULL, maximum, (void *)i);
  }

  for (int i = 0; i < T; i++) {
    pthread_join(threads[i], NULL);
  }

  ll max = 0;
  for (int i = 0; i < T; i++) {
    if (max_num[i] > max)
      max = max_num[i];
  }

  printf("Maximum Element is : %lld\n", max);

  return 0;
}
