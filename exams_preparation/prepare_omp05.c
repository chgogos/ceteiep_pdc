#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main() {
  double *a;
  double *b;
  double inner_prod = 0.0;

  a = (double *)malloc(sizeof(double) * N);
  b = (double *)malloc(sizeof(double) * N);
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    a[i] = (double)rand() / (double)RAND_MAX;
    b[i] = (double)rand() / (double)RAND_MAX;
  }

#pragma omp parallel for num_threads(5) reduction(+ : inner_prod)
  for (int i = 0; i < N; i++) {
    inner_prod += a[i] * b[i];
  }

  printf("%.2f\n", inner_prod);
  free(a);
  free(b);
}

/*
249875.97
*/