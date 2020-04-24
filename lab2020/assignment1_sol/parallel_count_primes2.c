#include "timer.h"
#include <assert.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

pthread_mutex_t m;

ll p_count = 1;

struct prime_arg {
  ll start;
  ll finish;
};

bool is_prime(ll x) {
  ll limit = (ll)sqrt(x);
  for (ll i = 2; i <= limit; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void *prime_work(void *arg) {
  struct prime_arg *parg = (struct prime_arg *)arg;
  ll local_count = 0;
  for (ll i = parg->start; i <= parg->finish; i += 2) {
    if (is_prime(i)) {
      local_count++;
    }
  }
  pthread_mutex_lock(&m);
  p_count += local_count;
  pthread_mutex_unlock(&m);
  return NULL;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Wrong arguments\n");
    exit(-1);
  }

  double start_t, finish_t, elapsed_t;
  GET_TIME(start_t);
  ll upto = atol(argv[1]);
  int T = atoi(argv[2]);
  assert(upto % T == 0);

  pthread_t *threads = malloc(sizeof(pthread_t) * T);
  struct prime_arg *targs = malloc(sizeof(struct prime_arg) * T);

  pthread_mutex_init(&m, NULL);
  for (int i = 0; i < T; i++) {
    targs[i].start = upto / T * i + 1;
    if (i == 0)
      targs[i].start = 3;
    targs[i].finish = upto / T * (i + 1);
    pthread_create(&threads[i], NULL, prime_work, &targs[i]);
  }

  for (int i = 0; i < T; i++) {
    pthread_join(threads[i], NULL);
  }
  pthread_mutex_destroy(&m);

  free(threads);
  free(targs);

  GET_TIME(finish_t);
  elapsed_t = finish_t - start_t;
  printf("Number of primes = %lld\n", p_count);
  printf("The code to be timed took %e seconds\n", elapsed_t);
}
