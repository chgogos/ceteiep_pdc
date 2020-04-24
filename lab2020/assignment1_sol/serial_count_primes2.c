/*
 * Υπολογισμός του πλήθους των πρώτων ακεραίων μέχρι και τον ακέραιο finish
 */

#include "timer.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
  if (argc != 2) {
    printf("Wrong arguments\n");
    exit(-1);
  }
  double start_t, finish_t, elapsed_t;
  GET_TIME(start_t);

  ll finish = atoll(argv[1]);

  ll p_count = 1;
  ll next_candidate = 3;

  while (next_candidate < finish) {
    if (is_prime(next_candidate))
      p_count++;
    next_candidate += 2;
  }

  GET_TIME(finish_t);
  elapsed_t = finish_t - start_t;
  printf("Number of primes = %lld\n", p_count);
  printf("The code to be timed took %e seconds\n", elapsed_t);
}

/*
#############################################
OS: macOS Catalina 10.15.3
CPU: 2,9 GHz Dual-Core Intel Core i7
RAM: 8 GB 1600 MHz DDR3
Cores/Threads: 2/4
C compiler: Apple clang version 11.0.0 (clang-1100.0.33.16)
#############################################
έξοδος για Ν = 1000000
#############################################
Number of primes = 78498
The code to be timed took 7.297640e-01 seconds

#############################################
έξοδος για Ν = 2000000
#############################################
Number of primes = 148933
The code to be timed took 1.960712e+00 seconds

#############################################
έξοδος για Ν = 4000000
#############################################
Number of primes = 283146
The code to be timed took 4.993275e+00 seconds

#############################################
έξοδος για Ν = 8000000
#############################################
Number of primes = 539777
The code to be timed took 1.308842e+01 seconds
*/
