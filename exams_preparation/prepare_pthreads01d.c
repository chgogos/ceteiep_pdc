// παραλλαγή της prepare_pthreads01.c με α) δημιουργία τυχαίων τιμών β)
// παραμέτρους γραμμής εντολών για τον ορισμό πλήθους στοιχείων πίνακα και
// πλήθους νημάτων και γ) χρήση mutex

#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long ll;

ll N;
ll T;

ll *a;
ll max;

pthread_mutex_t lock;

void *maximum(void *tid) {
  intptr_t mytid = (intptr_t)tid;
  ll maxs = 0;

  for (ll i = mytid * (N / T); i < (mytid + 1) * (N / T); i++) {
    if (a[i] > maxs)
      maxs = a[i];
  }
  pthread_mutex_lock(&lock);
  if (maxs>max)
    max= maxs;
  pthread_mutex_unlock(&lock);
}

int main(int argc, char *argv[]) {
  if (argc == 3) {
    N = atoi(argv[1]);
    T = atoi(argv[2]);
    if (N % T != 0) {
      printf("Wrong arguments!\n");
      exit(-1);
    }
  } else {
    N = 100000;
    T = 4;
  }
  a = malloc(sizeof(ll) * N);
  srand(time(NULL));
  for (ll i = 0; i < N; i++) {
    a[i] = (RAND_MAX + 1) * (ll)rand() +
           rand(); // get larger random number than RAND_MAX
  }

  pthread_t *threads = malloc(sizeof(pthread_t) * T);
  pthread_mutex_init(&lock, NULL);
  for (intptr_t i = 0; i < T; i++) {
    pthread_create(&threads[i], NULL, maximum, (void *)i);
  }

  for (int i = 0; i < T; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("Maximun Element is : %ld\n", max);

  pthread_mutex_destroy(&lock);
  free(threads);
  free(a);
  return 0;
}

/*
$  gcc prepare_pthreads01d.c -o prepare_pthreads01d -lpthread
$ prepare_pthreads01c 100000000 10
Maximun Element is : 1073741821
*/
