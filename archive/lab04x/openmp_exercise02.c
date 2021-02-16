#include <omp.h>
#include <stdio.h>
#include <stdlib.h> // atoi()

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <number> <number_of_threads>\n", argv[0]);
    exit(-1);
  }
  long long x;
  long long sum = 0;
  x = atoll(argv[1]);
  int thread_num = atoi(argv[2]);
#pragma omp parallel for num_threads(thread_num) reduction(+:sum)
  for (long long i = 0; i <= x; i++)
    sum += i;

  printf("The total sum is %lld\n", sum);
  return 0;
}