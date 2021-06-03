#include <pthread.h>
#include <stdio.h>
#define T 2

int gl = 0;
intptr_t flag = 0;

void *work(void *tid) {
  intptr_t id = (intptr_t)tid;
  int lo = 0;
  while (flag != id)
    ;
  ++lo;
  ++gl;
  printf("%ld %d %d ", id, gl, lo);
  flag++;
}

int main() {
  pthread_t threads[T];

  for (intptr_t i = 0; i < T; i++)
    pthread_create(&threads[i], NULL, work, (void *)i);

  for (int i = 0; i < T; i++)
    pthread_join(threads[i], NULL);
  printf("%d", gl);
  return 0;
}

/*
0 1 1 1 2 1 2
*/
