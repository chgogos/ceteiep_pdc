#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int is_done;
pthread_mutex_t done_lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t done_cond=PTHREAD_COND_INITIALIZER;

void* proc1(void* arg){
    pthread_mutex_lock(&done_lock);
    if (!is_done)
        pthread_cond_wait(&done_cond, &done_lock);
    pthread_mutex_unlock(&done_lock);
    printf("Message from thread 1\n");
  return NULL;
}

void* proc2(void* arg){
    printf("Message from thread 2 (sleeping for 2 seconds)\n");
    sleep(2);
    printf("Another message from thread 2\n");
    pthread_mutex_lock(&done_lock);
    is_done=1;
    pthread_cond_signal(&done_cond);
    pthread_mutex_unlock(&done_lock);
  return NULL;
}

// thread 2 must finishes before thread 1 continues
int main(int argc, char **argv) {
  pthread_t thread1, thread2;
  pthread_create(&thread1, NULL, proc1, NULL);
  pthread_create(&thread2, NULL, proc2, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_mutex_destroy(&done_lock);
  pthread_cond_destroy(&done_cond);
  return 0;
}
