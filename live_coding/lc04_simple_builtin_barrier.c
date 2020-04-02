// Υλοποίηση φράγματος με mutex και αναμονή σε εκρήγορση
// Μειονεκτήματα:
// 1) σπατάλη κύκλων ρολογιού της CPU λόγω του βρόχου αναμονής σε εκρήγορση
// (busy wait) 2) Ανάγκη χρήσης διαφορετικής μεταβλητής μετρητή για κάθε φράγμα

#include <pthread.h>
#include <stdint.h> // intptr_t
#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <unistd.h> // sleep

#define T 10
pthread_barrier_t barrier;

void *work(void *id) {
  intptr_t tid = (intptr_t)id;
  srand(time(NULL) * tid);
  int sleep_duration = rand() % 5 + 1;
  printf("Phase A. Thread %ld will sleep for %d seconds.\n", tid,
         sleep_duration);
  sleep(sleep_duration);

  printf("Phase B. Thread %ld woke up.\n", tid);
  return NULL;
}

int main() {
  pthread_barrier_init(&barrier, NULL, T);

  pthread_t thread_handles[T];
  for (intptr_t tid = 0; tid < T; tid++) {
    pthread_create(&thread_handles[tid], NULL, work, (void *)tid);
  }

  for (intptr_t tid = 0; tid < T; tid++) {
    pthread_join(thread_handles[tid], NULL);
  }
  pthread_barrier_destroy(&barrier);
}

/*
Phase A. Thread 0 will sleep for 4 seconds.
Phase A. Thread 3 will sleep for 2 seconds.
Phase A. Thread 2 will sleep for 1 seconds.
Phase A. Thread 1 will sleep for 5 seconds.
Phase A. Thread 4 will sleep for 4 seconds.
Phase A. Thread 5 will sleep for 5 seconds.
Phase A. Thread 7 will sleep for 2 seconds.
Phase A. Thread 6 will sleep for 1 seconds.
Phase A. Thread 8 will sleep for 5 seconds.
Phase A. Thread 9 will sleep for 1 seconds.
Phase B. Thread 0 woke up.
Phase B. Thread 1 woke up.
Phase B. Thread 2 woke up.
Phase B. Thread 5 woke up.
Phase B. Thread 3 woke up.
Phase B. Thread 8 woke up.
Phase B. Thread 6 woke up.
Phase B. Thread 7 woke up.
Phase B. Thread 9 woke up.
Phase B. Thread 4 woke up.
*/