#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
#pragma omp parallel num_threads(5)
  {
    int tid = omp_get_thread_num();
    srand(time(NULL) + tid);
    int x = rand() % 100 + 1;
    printf("Thread %d --> %d\n", tid, x);
  }
}