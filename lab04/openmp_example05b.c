#include <stdio.h>
#include <omp.h>

#define n 1000000000

double compute_pi_serial() {
  int k;
  double factor = 1.0;
  double sum = 0.0;
  for (k = 0; k < n; k++) {
    sum += factor / (2 * k + 1);
    factor = -factor;
  }
  return 4.0 * sum;
}

void compute_pi_parallel() {
  int k;
  double sum = 0.0, factor;
#pragma omp parallel for reduction(+ : sum) private(factor)
  for (k = 0; k < n; k++) {
    if (k % 2 == 0)
      factor = 1.0;
    else
      factor = -1.0;
    sum += factor / (2 * k + 1);
  }
  printf("Pi computed in parallel using 10^9 terms: %.14f\n", 4.0 * sum);
}

int main() {
  double start, finish;

  start = omp_get_wtime();
  printf("Pi computed serially using 10^9 terms  : %.14f\n",
         compute_pi_serial());
  finish = omp_get_wtime();
  printf("Time elapsed: %.2f\n", finish - start);

  start = omp_get_wtime();
  compute_pi_parallel();
  finish = omp_get_wtime();
  printf("Time elapsed: %.2f\n", finish - start);

  return 0;
}
