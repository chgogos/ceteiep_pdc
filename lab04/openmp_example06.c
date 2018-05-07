#include <stdio.h>
#include <math.h>
#include <omp.h>

// n=30000
// serial execution: 11.02 seconds
// parallel for : 5.83 seconds
// parallel for schedule(static, 1): 4.61 seconds

double f(int i) {
  int j, start = i * (i + 1) / 2, finish = start + i;
  double return_val = 0;
  for (j = start; j < finish; j++)
    return_val += sin(j);
  return return_val;
}

int main() {
  double sum;
  int i, n = 30000;
  double start, finish;

  start = omp_get_wtime();
  sum = 0;
  for (i = 0; i <= n; i++)
    sum += f(i);
  printf("The sum is %.2f\n", sum);
  finish = omp_get_wtime();
  printf("Time elapsed: %.2f (serial)\n", finish - start);

  start = omp_get_wtime();
  sum = 0;
// χρονοδιάγραμμα τύπου μπλοκ
#pragma omp parallel for num_threads(4) reduction(+ : sum)
  for (i = 0; i <= n; i++)
    sum += f(i);
  printf("The sum is %.2f\n", sum);
  finish = omp_get_wtime();
  printf("Time elapsed: %.2f (default schedule)\n", finish - start);

  start = omp_get_wtime();
  sum = 0;
// κυκλικό χρονοδιάγραμμα
#pragma omp parallel for num_threads(4) reduction(+ : sum) schedule(static, 1)
  for (i = 0; i <= n; i++)
    sum += f(i);
  printf("The sum is %.2f\n", sum);
  finish = omp_get_wtime();
  printf("Time elapsed: %.2f (cyclic schedule)\n", finish - start);
  return 0;
}