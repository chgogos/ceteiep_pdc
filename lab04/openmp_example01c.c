#include <stdio.h>
#include <omp.h>

int main() {
  printf("Message from the main thread\n");

  #pragma omp parallel
  printf("Hello from thread %d of %d\n", omp_get_thread_num(), my_rank, thread_count());

  return 0;
}