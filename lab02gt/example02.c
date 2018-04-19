#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char* msg;

void* thread_proc(void* arg){
  usleep(3000);

  msg = "A message from the created thread\n";

  return NULL;
}

int main(int argc, char **argv) {
  pthread_t thread;

  msg = NULL;

  pthread_create(&thread, NULL, thread_proc, NULL);

  // pthread_join(thread, NULL);

  printf("%s", msg);
  return 0;
}
