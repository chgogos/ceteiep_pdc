#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void* f1(void* arg){
  int whos_better;
  whos_better = 1;
  while(1)
    printf("Thread 1: thread %d is better.\n", whos_better);

  return NULL;
}

void* f2(void* arg){
  int whos_better;
  whos_better = 2;
  while(1)
    printf("Thread 2: thread %d is better.\n", whos_better);

  return NULL;
}

// each thread prints its value of whos_better
int main(int argc, char **argv) {
  pthread_t th1, th2;

  pthread_create(&th1, NULL, f1, NULL);
  pthread_create(&th2, NULL, f2, NULL);

  pthread_join(th1, NULL);
  pthread_join(th2, NULL);

  pthread_exit(NULL);
}
