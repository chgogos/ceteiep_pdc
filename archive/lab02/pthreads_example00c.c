#include <pthread.h>
#include <stdio.h>
#include <stdint.h> // intptr_t

#define N 10

void *hello(void *rank)
{
  printf("This is a message from thread: %ld\n", (intptr_t)rank);
  return NULL;
}

int main()
{
  pthread_t th[N];
  for (intptr_t i = 0; i < N; i++)
    pthread_create(&th[i], NULL, hello, (void *)i);

  printf("This is a message from the main thread\n");

  for (intptr_t i = 0; i < N; i++)
    pthread_join(th[i], NULL);

  return 0;
}
