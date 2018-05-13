#include <stdio.h>
#include <omp.h>

#define n 1000000000

double compute_pi_serial() {
  int i = 0;
  double pi = 0.0, w = 1.0 / n;
  for (i = 0; i < n; i++)
    pi += 4 * w / (1 + (i + 0.5) * (i + 0.5) * w * w);
  return pi;
}

void compute_pi_parallel() {
  int i;
  double pi = 0.0, mysum = 0.0, w = 1.0 / n;
  #pragma omp parallel firstprivate(mysum) num_threads(1000)
  {
    #pragma omp for
    for (i = 0; i < n; i++)
      mysum += 4 * w / (1 + (i + 0.5) * (i + 0.5) * w * w);

    #pragma omp critical
    pi += mysum;
  }
  printf("Pi computed in parallel using 10^9 terms: %.14f\n", pi);
}

void compute_pi_parallel_using_reduction() {
  int i;
  double pi = 0.0, w = 1.0 / n;
  #pragma omp parallel for reduction(+ : pi)
  for (i = 0; i < n; i++)
    pi += 4 * w / (1 + (i + 0.5) * (i + 0.5) * w * w);

  printf("Pi computed in parallel(reduction) using 10^9 terms: %.14f\n", pi);
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

  start = omp_get_wtime();
  compute_pi_parallel_using_reduction();
  finish = omp_get_wtime();
  printf("Time elapsed: %.2f\n", finish - start);

  return 0;
}