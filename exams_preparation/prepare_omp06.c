#include <omp.h>
#include <stdio.h>

#define N 8

int main() {
// #pragma omp parallel for num_threads(4) 
#pragma omp parallel for num_threads(4) schedule(static, 1)
for (int i = 0; i < N; i++) {
    int my_rank=omp_get_thread_num();
    if (my_rank==3)
      printf("%d ", i);
  }
  
  return 0;
}

/*
εμφανίζει:
4 0
για schedule(static,1) εμφανίζει:
3 7
*/