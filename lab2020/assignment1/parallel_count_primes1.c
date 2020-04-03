#include "timer.h"
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

#define N 20000000

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

int main() {
  double start_t, finish_t, elapsed_t;
  GET_TIME(start_t);

  struct prime_arg t1arg = {3, N / 2};
  struct prime_arg t2arg = {N / 2 + 1, N};

  pthread_mutex_init(&m, NULL);
  pthread_t t1, t2;
  pthread_create(&t1, NULL, prime_work, &t1arg);
  pthread_create(&t2, NULL, prime_work, &t2arg);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_mutex_destroy(&m);

  GET_TIME(finish_t);
  elapsed_t = finish_t - start_t;
  printf("Number of primes = %ld\n", p_count);
  printf("The code to be timed took %e seconds\n", elapsed_t);
}
