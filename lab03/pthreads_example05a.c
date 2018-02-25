#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define T 10
pthread_barrier_t bar;

void *thread_func(void *tid) { 
    long mytid = (long)tid;
    printf("Thread %ld phase A\n",mytid);    
    pthread_barrier_wait(&bar);
    printf("Thread %ld phase B\n",mytid); 
    return NULL;
}

int main() {
  pthread_barrier_init(&bar, NULL, T);
  pthread_t thread_handles[T];
  for (long t = 0; t < T; t++)
    pthread_create(&thread_handles[t], NULL, thread_func, (void *)t);

  for (long t = 0; t < T; t++)
    pthread_join(thread_handles[t], NULL);
  pthread_barrier_destroy(&bar);
  return 0;
}