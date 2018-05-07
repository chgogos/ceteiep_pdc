#include <stdio.h>
#include <omp.h>

void main() {
  int a = 1, b = 1, c = 1, d = 1;
  printf("START a=%d b=%d c=%d d=%d\n", a, b, c, d);
#pragma omp parallel default(none) private(a) firstprivate(b) shared(c,d)
{
  int id = omp_get_thread_num();  
  printf("entering thread id=%d a=%d b=%d c=%d d=%d\n", id, a, b, c, d);
  a = 2;
  b = 2;
  c = 2;
  d = 2;
  printf("exiting thread id=%d a=%d b=%d c=%d d=%d\n", id, a, b, c, d);
}
printf("END a=%d b=%d c=%d d=%d\n", a, b, c, d);
}