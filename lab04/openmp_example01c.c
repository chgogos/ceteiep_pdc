#include <stdio.h>
#include <omp.h>

int main() {
  printf("Message from the main thread\n");

  #pragma omp parallel
  printf("Hello from thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());

  return 0;
}