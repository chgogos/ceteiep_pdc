// Χειρισμός του race condition με semaphore
// Λειτουργεί σωστά σε Linux, Windows με MinGW-W64 8.1.0

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define T 10

int counter = 0;
sem_t sem;

void *work(void *id) {
  long tid = (long)id;
  printf("Thread %ld started\n", tid);
  for (int i = 0; i < 1000000; i++) {
    sem_wait(&sem);
    // κρίσιμο τμήμα (αρχή)
    if (i % 2 == 0)
      counter++;
    else
      counter--;
    // κρίσιμο τμήμα (τέλος)
    sem_post(&sem);
  }
  printf("Thread %ld finished\n", tid);
  return NULL;
}

int main() {
  pthread_t thread_handles[T];
  sem_init(&sem, 0, 1); // ξεκλείδωμα σηματοφορέα
  for (long tid = 0; tid < T; tid++) {
    pthread_create(&thread_handles[tid], NULL, work, (void *)tid);
  }
  for (int i = 0; i < T; i++) {
    pthread_join(thread_handles[i], NULL);
  }
  printf("counter = %d\n", counter);
  sem_destroy(&sem);
}
