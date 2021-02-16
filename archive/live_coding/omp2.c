#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  double start, finish;
  start = omp_get_wtime();
  if (argc != 3) {
    printf("wrong number of arguments\n");
    exit(-1);
  }
  long long x = atoll(argv[1]);
  int threads = atoi(argv[2]);
  printf("Numbers: %lld Threads: %d\n", x, threads);

  long long sum = 0;
#pragma omp parallel for num_threads(threads) reduction(+ : sum)
  for (long long i = 1; i <= x; i++) {
    sum += i;
  }
  finish = omp_get_wtime();

  printf("The total sum is %lld  (time=%.4f)\n", sum, finish - start);
}