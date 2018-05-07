#include <stdio.h>
#include <omp.h>
static long num_steps = 100000000;
double step;

void main() {
  for (int NUM_THREADS = 1; NUM_THREADS <= 8; NUM_THREADS++) {
    double start = omp_get_wtime(), finish, pi=0.0, sum=0.0;
    step = 1.0 / (double)num_steps;
    omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
    {
      double x;
      #pragma omp for reduction(+:sum)
      for (int i = 0; i < num_steps; i++) {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
      }
    }
    pi += sum * step;
    finish = omp_get_wtime();
    printf("Threads=%d --> pi = %.9f time elapsed = "
           "%.4f\n",
           NUM_THREADS, pi, finish - start);
  }
}