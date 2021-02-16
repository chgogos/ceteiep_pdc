#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define T 10

pthread_barrier_t bar;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int shared_variable = 0;

void *thread_func(void *tid)
{
  long mytid = (long)tid;
  pthread_mutex_lock(&lock);
  shared_variable++;
  printf("Thread %ld added 1 to the shared value, shared value=%d\n", mytid, shared_variable);
  pthread_mutex_unlock(&lock);
  pthread_barrier_wait(&bar);
  pthread_mutex_lock(&lock);
  shared_variable *= 2;
  printf("Thread %ld doubled shared value, shared value=%d\n", mytid, shared_variable);
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main()
{
  pthread_barrier_init(&bar, NULL, T);
  pthread_t thread_handles[T];
  for (long t = 0; t < T; t++)
    pthread_create(&thread_handles[t], NULL, thread_func, (void *)t);
  for (long t = 0; t < T; t++)
    pthread_join(thread_handles[t], NULL);
  pthread_barrier_destroy(&bar);
  printf("The final result is %d\n", shared_variable);
  return 0;
}
