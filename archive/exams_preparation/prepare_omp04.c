#include <omp.h>
#include <stdio.h>

#define N 4

int main() {
  int a = 0;
  int b = 0;
#pragma omp parallel for default(none) shared(a) private(b) num_threads(4)
  for (int i = 0; i < N; i++) {
    a++;
    b++;
  }
  printf("%d %d\n", a, b);

  return 0;
}

/*
4 0
*/