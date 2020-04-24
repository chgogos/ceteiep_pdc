/*
 * Υπολογισμός του πλήθους των πρώτων ακεραίων μέχρι και τον ακέραιο finish
 */

#include "timer.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define N 4000000

typedef long long ll;

bool is_prime(ll x) {
  ll limit = (ll)sqrt(x);
  for (ll i = 2; i <= limit; i++) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main() {
  double start_t, finish_t, elapsed_t;
  GET_TIME(start_t);

  ll finish = N;
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
OS: Windows 10
CPU: Intel Core i7 7700K
RAM: 16GB
Cores/Threads: 4/8
C compiler: gcc (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
#############################################
έξοδος για Ν = 4000000
#############################################
Number of primes = 283146
The code to be timed took 2.237571e+00 seconds
*/

/*
#############################################
OS: macOS Catalina 10.15.3
CPU: 2,9 GHz Dual-Core Intel Core i7
RAM: 8 GB 1600 MHz DDR3
Cores/Threads: 2/4
C compiler: Apple clang version 11.0.0 (clang-1100.0.33.16)
#############################################
έξοδος για Ν = 4000000
#############################################
Number of primes = 283146
The code to be timed took 4.847461e+00 seconds
*/
