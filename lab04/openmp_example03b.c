#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// example f(x)=x^2
double f(double x) { return x * x; }

double trapezio_parallel(double a, double b, int n) {
  double h, x, my_result, local_a, local_b;
  int i, local_n;
  int my_rank = omp_get_thread_num();
  int thread_count = omp_get_num_threads();
  h = (b - a) / n;
  local_n = n / thread_count;
  local_a = a + my_rank * local_n * h;
  local_b = local_a + local_n * h;
  my_result = (f(local_a) + f(local_b)) / 2.0;
  for (i = 1; i <= local_n - 1; i++) {
    x = local_a + i * h;
    my_result += f(x);
  }
  my_result *= h;
  return my_result;
}

int main(int argc, char **argv) {
  double global_result = 0.0;
  int n = 1000000000;
  double a = 0.0, b = 10.0;

  #pragma omp parallel num_threads(5)
  {
    double my_result = trapezio_parallel(a, b, n);
    #pragma omp critical
    global_result += my_result;
  }
  printf("result from the parallel code: %.5f\n", global_result);
  return 0;
}
