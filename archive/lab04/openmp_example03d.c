#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

// example f(x)=x^2
double f(double x) { return x * x; }

double trapezio(double a, double b, int n) {
  double x_i, approx;
  int i;
  double h = (b - a) / n;
  approx = (f(a) + f(b)) / 2.0;
  #pragma omp parallel for num_threads(5) reduction(+:approx)
  for (i = 1; i <= n - 1; i++) {
    x_i = a + i * h;
    approx += f(x_i);
  }
  approx *= h;
  return approx;
}

int main(int argc, char **argv) {
  double global_result = 0.0;

  int n = 1000000000;
  double approx;
  double a = 0.0, b = 10.0;
  approx = trapezio(a, b, n);
  printf("result from the parallel code: %.5f\n", approx);

  return 0;
}
