#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep

#define T 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

int shared_value = -1;
int flag = 0;
void *produce(void *tid)
{
  long mytid = (long)tid;
  printf("Producer thread %ld is busy, consumers have to wait\n", mytid);
  sleep(2);
  shared_value = 42;
  printf("Thread %ld produced shared value %d\n", mytid, shared_value);
  pthread_mutex_lock(&lock);
  flag = 1;
  if (flag == 1)
    pthread_cond_broadcast(&cond_var);
  pthread_mutex_unlock(&lock);
  return NULL;
}

void *consume(void *tid)
{
  long mytid = (long)tid;
  pthread_mutex_lock(&lock);
  if (flag == 0)
    pthread_cond_wait(&cond_var, &lock);
  pthread_mutex_unlock(&lock);
  printf("Consumer thread %ld reads shared value %d\n", mytid, shared_value);
  return NULL;
}

int main()
{
  pthread_t thread_handles[T];
  pthread_create(&thread_handles[0], NULL, produce, (void *)0);
  for (long t = 1; t < T; t++)
    pthread_create(&thread_handles[t], NULL, consume, (void *)t);

  for (long t = 0; t < T; t++)
    pthread_join(thread_handles[t], NULL);

  printf("Main: shared value %d\n", shared_value);
  pthread_mutex_destroy(&lock);
  pthread_cond_destroy(&cond_var);
  return 0;
}