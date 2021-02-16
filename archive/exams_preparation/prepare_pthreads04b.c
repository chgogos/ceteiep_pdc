#include <pthread.h>
#include <stdio.h>

#define T 5

int gl = 0;
intptr_t flag = 0;

void *work(void *tid) {
  intptr_t id = (intptr_t)tid;

  int lo = 0;
  static int st = 0;

  while (flag != id)
    ;
  ++lo;
  ++st;
  ++gl;
  printf("THREAD ID: %ld, Static: %d, Global: %d Local:%d\n", id, st, gl, lo);
  flag++;
}

int main() {
  pthread_t threads[T];

  for (intptr_t i = 0; i < T; i++)
    pthread_create(&threads[i], NULL, work, (void *)i);

  for (int i = 0; i < T; i++)
    pthread_join(threads[i], NULL);
  printf("Global: %d\n", gl);
  return 0;
}

/*
THREAD ID: 0, Static: 1, Global: 1 Local:1
THREAD ID: 1, Static: 2, Global: 2 Local:1
THREAD ID: 2, Static: 3, Global: 3 Local:1
THREAD ID: 3, Static: 4, Global: 4 Local:1
THREAD ID: 4, Static: 5, Global: 5 Local:1
Global: 5
*/