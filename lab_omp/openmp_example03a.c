#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

// example f(x)=x^2
double f(double x) { return x * x; }

double trapezio_serial(double a, double b, int n) {
  double x_i, approx;
  int i;
  double h = (b - a) / n;
  approx = (f(a) + f(b)) / 2.0;
  for (i = 1; i <= n - 1; i++) {
    x_i = a + i * h;
    approx += f(x_i);
  }
  approx *= h;
  return approx;
}

void trapezio_parallel(double a, double b, int n, double *global_result) {
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

  #pragma omp critical
  *global_result += my_result;
}

int main(int argc, char **argv) {
  double global_result = 0.0;

  int n = 1000000000;
  double approx;
  double a = 0.0, b = 10.0;
  approx = trapezio_serial(a, b, n);
  printf("result from the serial code: %.5f\n", approx);

  #pragma omp parallel num_threads(5)
  trapezio_parallel(a, b, n, &global_result);

  printf("result from the parallel code: %.5f\n", global_result);
  return 0;
}
