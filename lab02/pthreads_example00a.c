#include <pthread.h>
#include <stdio.h>

void *hello(void *thread_name) {
  printf("This is a message from thread: %s\n", (char *) thread_name);
  return NULL;
}

int main() {
  pthread_t th1, th2;
  pthread_create(&th1, NULL, hello, "A");
  pthread_create(&th2, NULL, hello, "B");

  printf("This is a message from the main thread\n");

  pthread_join(th1, NULL);
  pthread_join(th2, NULL);
  return 0;
}
