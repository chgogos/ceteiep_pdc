#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define T 4

int main() {
  int A[N];
  int B[N];
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    A[i] = rand() % 10 + 1;
    B[i] = rand() % 10 + 1;
  }
  int q = 0;
  for (int i = 0; i < N; i++)
    q += A[i] * B[i];
  printf("dot product (serial)=%d\n", q);

  q = 0;
#pragma omp parallel for num_threads(4) reduction(+ : q)
  for (int i = 0; i < N; i++)
    q += A[i] * B[i];

  printf("dot product (parallel)=%d\n", q);
  return 0;
}
