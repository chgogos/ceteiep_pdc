#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;
int flag = 0;

void *funA(void *id) {
  while (flag < 2)
    ;
  printf("T1:start\n");
  pthread_mutex_lock(&m);
  printf("T1:work\n");
  sleep(2);
  pthread_cond_broadcast(&c);
  printf("T1:broadcast\n");
  pthread_mutex_unlock(&m);
  printf("T1:finish\n");
  return NULL;
}

void *funB(void *id) {
  intptr_t tid = (intptr_t)id;
  printf("T%d:start\n", tid);
  pthread_mutex_lock(&m);
  flag++;
  printf("T%d:wait T1 to finish\n", tid);
  while (pthread_cond_wait(&c, &m) != 0)
    ;
  printf("T%d:work\n", tid);
  pthread_mutex_unlock(&m);
  printf("T%d:finish\n", tid);
  return NULL;
}

int main() {
  pthread_t t1, t2, t3;
  pthread_create(&t1, NULL, funA, NULL);
  pthread_create(&t2, NULL, funB, (void *)2);
  pthread_create(&t3, NULL, funB, (void *)3);

  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
}

/*
T3:start
T3:wait T1 to finish
T2:start
T2:wait T1 to finish
T1:start
T1:work
T1:broadcast
T1:finish
T2:work
T2:finish
T3:work
T3:finish
*/