#include <stdio.h>
#include <stdlib.h> // srnad(), rand()
#include <omp.h>
#include <time.h> // time()

#define T 5

int main() {
#pragma omp parallel num_threads(5)
  {
    int tid = omp_get_thread_num();
    srand(time(NULL) + tid);
    int x = rand() % 101 + 1;
    printf("Thread %d --> %d\n", tid, x);
  }
}