#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

// Pacheco (program 4.1 )
// gcc -g -Wall -pthread pthreads_example01a.c -o pthreads_example01a
// ./pthreads_example01a 4

int thread_count; // καθολική μεταβλητή

void *hello(void *rank)
{
  long myrank = (long)rank;
  pthread_t thread_internal_id = pthread_self();
  printf("Hello from thread %ld (opaque thread id: %lu) of %d\n", myrank,
         (unsigned long)thread_internal_id, thread_count);
  return NULL;
}

int main(int argc, char *argv[])
{
  long thread;
  thread_count = strtol(argv[1], NULL, 0);
  pthread_t *thread_handles;
  thread_handles = malloc(thread_count * sizeof(pthread_t));
  for (thread = 0; thread < thread_count; thread++)
  {
    pthread_create(&thread_handles[thread], NULL, hello, (void *)thread);
  }
  printf("Hello from the main thread\n");
  for (thread = 0; thread < thread_count; thread++)
  {
    pthread_join(thread_handles[thread], NULL);
  }
  free(thread_handles);
  return 0;
}
