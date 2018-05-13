#include <stdio.h>
#include <omp.h>

int main() {
  int a = 1, b = 1, c = 1, d = 1;
  printf("1. a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);

  #pragma omp parallel shared(b), private(c), firstprivate(d) num_threads(4)
  {
    // c=1;
    c++;
    d++;
    #pragma omp critical
    {
      a++;
      b++;
    }
    printf("2. [%d] a=%d, b=%d, c=%d, d=%d\n", omp_get_thread_num(), a, b, c,
           d);
  }
  printf("3. a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
  return 0;
}