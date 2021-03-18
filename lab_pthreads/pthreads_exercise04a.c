#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int TOTAL_POINTS; // number of points
int T;            // number of threads
int k = 0;        // number of points inside the circle
pthread_mutex_t mx = PTHREAD_MUTEX_INITIALIZER;

void *work(void *tid) {
  long mytid = (long)tid;
  srand48(time(NULL) * mytid);
  int points = TOTAL_POINTS / T;
  if ((mytid == T - 1) && (TOTAL_POINTS % T != 0))
    points += TOTAL_POINTS % T;
  int c = 0;
  for (int i = 0; i < points; i++) {
    double x, y, d;
    x = drand48(); // not thread safe
    y = drand48(); // not thread safe
    x = x * 2 - 1;
    y = y * 2 - 1;
    d = sqrt(x * x + y * y);
    if (d < 1)
      c++;
  }
  printf("Thread %ld points inside circle %d out of %d\n", mytid, c, points);
  pthread_mutex_lock(&mx);
  k += c;
  pthread_mutex_unlock(&mx);
  return NULL;
}

int main(int argc, char **argv) {
  TOTAL_POINTS = atoi(argv[1]);
  T = atoi(argv[2]);
  pthread_t *thread_handles;
  thread_handles = malloc(sizeof(pthread_t) * T);
  for (long i = 0; i < T; i++)
    pthread_create(&thread_handles[i], NULL, work, (void *)i);
  for (long i = 0; i < T; i++)
    pthread_join(thread_handles[i], NULL);
  double pi = (double)k / (double)TOTAL_POINTS * 4;
  printf("PI estimation %f\n", pi);
  pthread_mutex_destroy(&mx);
  free(thread_handles);
  return 0;
}