#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define T 5

void *thread_work(void *tid) {
  long mytid = (long)tid;
  srand(time(NULL) + mytid);
  long x = random() % 100 + 1;
  printf("Thread %ld --> %ld\n", mytid, x);
  return NULL;
}

int main() {
  pthread_t threads[T];
  for (long t = 0; t < T; t++)
    pthread_create(&threads[t], NULL, thread_work, (void *)t);

  for (long t = 0; t < T; t++)
    pthread_join(threads[t], NULL);
  return 0;
}