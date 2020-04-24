/*
 * Υπολογισμός του πλήθους των πρώτων ακεραίων μέχρι και τον ακέραιο finish
 */

#include "timer.h"
#include <math.h>
#include <omp.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // atoi


typedef long long ll;

bool is_prime(ll x) {
  ll limit = (ll)sqrt(x);
  for (ll i = 2; i <= limit; i++) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Wrong arguments\n");
    exit(-1);
  }
  double start_t, finish_t, elapsed_t;
  GET_TIME(start_t);

  ll finish = atoll(argv[1]);
  int threads = atoi(argv[2]);
  ll p_count = 1;

#pragma omp parallel for num_threads(threads) schedule(dynamic) reduction(+ \
                                                                          : p_count)
  for (ll next_candidate = 3; next_candidate < finish; next_candidate += 2) {
    if (is_prime(next_candidate))
      p_count++;
  }

  GET_TIME(finish_t);
  elapsed_t = finish_t - start_t;
  printf("Number of primes = %lld\n", p_count);
  printf("The code to be timed took %e seconds\n", elapsed_t);
}