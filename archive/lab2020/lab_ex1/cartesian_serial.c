#include "timer.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 30000 // αριθμός σημείων στο καρτεσιανό επίπεδο
#define DISTANCE 0.1 // απόσταση σημείων

struct point {
  double x, y;
};

int main() {
  int counter = 0;
  long seed = 1821L;
  srand(seed);
  struct point points[N];
  for (int i = 0; i < N; i++) {
    points[i].x = (double)rand() / RAND_MAX * 2.0 - 1.0;
    points[i].y = (double)rand() / RAND_MAX * 2.0 - 1.0;
  }

  double start, finish, elapsed;
  GET_TIME(start);

  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) {
      double x = points[i].x - points[j].x;
      double y = points[i].y - points[j].y;
      if (sqrt(pow(x, 2) + pow(y, 2)) < DISTANCE)
        counter++;
    }

  GET_TIME(finish);
  elapsed = finish - start;
  printf("Result: %d\n", counter);
  printf("The code to be timed took %e seconds\n", elapsed);
}

/*
#############################################
OS: Windows 10
CPU: Intel Core i7 7700K
RAM: 16GB
Cores/Threads: 4/8
C compiler: gcc (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
#############################################
έξοδος:
#############################################

Result: 3383803
The code to be timed took 1.583900e+001 seconds
*/
