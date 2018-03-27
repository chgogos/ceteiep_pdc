#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define T 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

int c = 0;
int values[T - 1];
void *produce(void *tid) {
  long mytid = (long)tid;
  printf("Thread %ld produces value 1\n", mytid);
  values[mytid] = 1;
  pthread_mutex_lock(&lock);
  c++;
  if (c == T - 1)
    pthread_cond_signal(&cond_var);
  pthread_mutex_unlock(&lock);
  return NULL;
}

void *consume(void *tid) {
  long mytid = (long)tid;
  pthread_mutex_lock(&lock);
  if (c < T - 1)
    pthread_cond_wait(&cond_var, &lock);
  pthread_mutex_unlock(&lock);
  for (int i = 0; i < T - 1; i++)
    values[i] *= 2;
  printf("Consumer thread %ld doubled all values\n", mytid);
  return NULL;
}

int main() {
  pthread_t thread_handles[T];
  for (long t = 0; t < T - 1; t++)
    pthread_create(&thread_handles[t], NULL, produce, (void *)t);
  pthread_create(&thread_handles[T - 1], NULL, consume, (void *)T - 1);

  for (long t = 0; t < T; t++)
    pthread_join(thread_handles[t], NULL);

  int sum = 0;
  for (int i = 0; i < T - 1; i++)
    sum += values[i];
  printf("Main: The sum is %d\n", sum);
  pthread_mutex_destroy(&lock);
  pthread_cond_destroy(&cond_var);
  return 0;
}
