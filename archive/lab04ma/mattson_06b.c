#include <stdio.h>
#include <omp.h>
#define PAD 8
static long num_steps = 100000000;
double step;

void main() {
  for (int NUM_THREADS = 1; NUM_THREADS <= 8; NUM_THREADS++) {
    double start = omp_get_wtime(), finish;
    int i, nthreads;
    double pi, sum[NUM_THREADS][PAD];
    step = 1.0 / (double)num_steps;
    omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
    {
      int i, id, nthrds;
      double x;
      id = omp_get_thread_num();
      nthrds = omp_get_num_threads();
      if (id == 0)
        nthreads = nthrds;
      for (i = id, sum[id][0] = 0.0; i < num_steps; i = i + nthrds) {
        x = (i + 0.5) * step;
        sum[id][0] += 4.0 / (1.0 + x * x);
      }
    }
    for (i = 0, pi = 0.0; i < nthreads; i++)
      pi += sum[i][0] * step;
    finish = omp_get_wtime();
    printf("Threads requested=%d Threads given=%d --> pi = %.9f time elapsed = "
           "%.4f\n",
           NUM_THREADS, nthreads, pi, finish - start);
  }
}