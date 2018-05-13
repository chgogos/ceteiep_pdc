#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void bubble_sort_serial(int *a, int n) {
  int i, list_length, tmp;
  for (list_length = n; list_length >= 2; list_length--)
    for (i = 0; i < list_length - 1; i++)
      if (a[i] > a[i + 1]) {
        tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
      }
}

void odd_even_sort_serial(int *a, int n) {
  int i, phase, tmp;
  for (phase = 0; phase < n; phase++)
    if (phase % 2 == 0) {
      for (i = 1; i < n; i += 2)
        if (a[i - 1] > a[i]) {
          tmp = a[i];
          a[i] = a[i - 1];
          a[i - 1] = tmp;
        }
    } else {
      for (i = 1; i < n - 1; i += 2)
        if (a[i] > a[i + 1]) {
          tmp = a[i];
          a[i] = a[i + 1];
          a[i + 1] = tmp;
        }
    }
}

void odd_even_sort_parallel1(int *a, int n, int thread_count) {
  int i, phase, tmp;
  for (phase = 0; phase < n; phase++)
    if (phase % 2 == 0) {
      #pragma omp parallel for num_threads(thread_count) default(none)               \
      shared(a, n) private(i, tmp)
      for (i = 1; i < n; i += 2)
        if (a[i - 1] > a[i]) {
          tmp = a[i];
          a[i] = a[i - 1];
          a[i - 1] = tmp;
        }
    } else {
      #pragma omp parallel for num_threads(thread_count) default(none)               \
      shared(a, n) private(i, tmp)
      for (i = 1; i < n - 1; i += 2)
        if (a[i] > a[i + 1]) {
          tmp = a[i];
          a[i] = a[i + 1];
          a[i + 1] = tmp;
        }
    }
}

void odd_even_sort_parallel2(int *a, int n, int thread_count) {
  int i, phase, tmp;
  #pragma omp parallel num_threads(thread_count) default(none)                   \
  shared(a, n) private(i, tmp, phase)
  for (phase = 0; phase < n; phase++)
    if (phase % 2 == 0) {
      #pragma omp for
      for (i = 1; i < n; i += 2)
        if (a[i - 1] > a[i]) {
          tmp = a[i];
          a[i] = a[i - 1];
          a[i - 1] = tmp;
        }
    } else {
      #pragma omp for
      for (i = 1; i < n - 1; i += 2)
        if (a[i] > a[i + 1]) {
          tmp = a[i];
          a[i] = a[i + 1];
          a[i + 1] = tmp;
        }
    }
}

void test() {
  int i, a[10] = {2, 1, 8, 3, 5, 6, 9, 0, 7, 4};
  // bubble_sort_serial(a, 10);
  odd_even_sort_serial(a, 10);
  for (i = 0; i < 10; i++)
    printf("%d ", a[i]);
}

int main() {
  int i, n = 40000;
  int a[n], c[n];
  double start, finish;
  srand(12345L);

  for (i = 0; i < n; i++)
    c[i] = a[i] = rand() % 1000000;
  start = omp_get_wtime();
  bubble_sort_serial(a, n);
  finish = omp_get_wtime();
  printf("Time elapsed bubble sort serial %.2f seconds\n", finish - start);

  for (i = 0; i < n; i++)
    a[i] = c[i];
  start = omp_get_wtime();
  odd_even_sort_serial(a, n);
  finish = omp_get_wtime();
  printf("Time elapsed odd even sort serial %.2f seconds\n", finish - start);

  for (i = 0; i < n; i++)
    a[i] = c[i];
  start = omp_get_wtime();
  odd_even_sort_parallel1(a, n, 4);
  finish = omp_get_wtime();
  printf("Time elapsed odd even sort parallel1 %.2f seconds\n", finish - start);

  for (i = 0; i < n; i++)
    a[i] = c[i];
  start = omp_get_wtime();
  odd_even_sort_parallel2(a, n, 4);
  finish = omp_get_wtime();
  printf("Time elapsed odd even sort parallel2 %.2f seconds\n", finish - start);

  return 0;
}