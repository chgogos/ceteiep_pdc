#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int TOTAL_POINTS; // number of points
int T;            // number of threads

int main(int argc, char **argv) {
  TOTAL_POINTS = atoi(argv[1]);
  T = atoi(argv[2]);
  int k = 0; // number of points inside the circle
  srand(time(NULL));

#pragma omp paralell for num_threads(T) reduction(+ : k)
  for (int i = 0; i < TOTAL_POINTS; i++) {
    double x, y, d;
    x = rand()/(double)RAND_MAX;
    y = rand()/(double)RAND_MAX;
    x = x * 2 - 1;
    y = y * 2 - 1;
    d = sqrt(x * x + y * y);
    if (d < 1)
      k++;
  }

  double pi = (double)k / (double)TOTAL_POINTS * 4;
  printf("PI estimation %f\n", pi);
  return 0;
}