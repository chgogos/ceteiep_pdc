// τοπικός μετρητής για κάθε νήμα, συγχρονισμός νημάτων με mutex

#include "timer.h"
#include <math.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define N 30000 // αριθμός σημείων στο καρτεσιανό επίπεδο
#define DISTANCE 0.1 // απόσταση σημείων
#define T 4          // πλήθος νημάτων

struct point {
  double x, y;
};

int counter = 0;
struct point points[N];
pthread_mutex_t mutex;

void *work(void *tid) {
  intptr_t id = (intptr_t)tid;
  int from = id * N / T;
  int to = (id + 1) * N / T;
  int c = 0;
  for (int i = from; i < to; i++)
    for (int j = i + 1; j < N; j++) {
      double x = points[i].x - points[j].x;
      double y = points[i].y - points[j].y;
      if (sqrt(pow(x, 2) + pow(y, 2)) < DISTANCE) {
        c++;
      }
    }
  pthread_mutex_lock(&mutex);
  counter += c;
  pthread_mutex_unlock(&mutex);
  return NULL;
}

int main() {
  long seed = 1821L;
  srand(seed);
  for (int i = 0; i < N; i++) {
    points[i].x = (double)rand() / RAND_MAX * 2.0 - 1.0;
    points[i].y = (double)rand() / RAND_MAX * 2.0 - 1.0;
  }

  double start, finish, elapsed;
  GET_TIME(start);

  pthread_t handles[T];
  pthread_mutex_init(&mutex, NULL);
  for (intptr_t tid = 0; tid < T; tid++)
    pthread_create(&handles[tid], NULL, work, (void *)tid);

  for (intptr_t tid = 0; tid < T; tid++)
    pthread_join(handles[tid], NULL);
  pthread_mutex_destroy(&mutex);

  GET_TIME(finish);
  elapsed = finish - start;
  printf("Number of points: %d\n", counter);
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

Number of points: 3383803
The code to be timed took 7.498025e+000 seconds
*/