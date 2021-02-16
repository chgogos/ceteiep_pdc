// Υλοποίηση φράγματος με mutex και αναμονή σε εκρήγορση
// Μειονεκτήματα:
// 1) σπατάλη κύκλων ρολογιού της CPU λόγω του βρόχου αναμονής σε εκρήγορση
// (busy wait)
// 2) Ανάγκη χρήσης διαφορετικής μεταβλητής μετρητή για κάθε φράγμα

#include <pthread.h>
#include <stdint.h> // intptr_t
#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <unistd.h> // sleep


#define T 10

int counter = 0;
pthread_mutex_t barrier_mutex;

void *work(void *id) {
  intptr_t tid = (intptr_t)id;
  srand(time(NULL) * tid);
  int sleep_duration = rand() % 5 + 1;
  sleep(sleep_duration);
  printf("Phase A. Thread %ld was ordered to sleep for %d seconds.\n", tid,
         sleep_duration);

  pthread_mutex_lock(&barrier_mutex);
  counter++;
  pthread_mutex_unlock(&barrier_mutex);
  while (counter < T)
    ;

  printf("Phase B. Thread %ld woke up.\n", tid);
  return NULL;
}

int main() {
  pthread_mutex_init(&barrier_mutex, NULL);

  pthread_t thread_handles[T];
  for (intptr_t tid = 0; tid < T; tid++) {
    pthread_create(&thread_handles[tid], NULL, work, (void *)tid);
  }

  for (intptr_t tid = 0; tid < T; tid++) {
    pthread_join(thread_handles[tid], NULL);
  }
  pthread_mutex_destroy(&barrier_mutex);
}

/*
Phase A. Thread 3 was ordered to sleep for 3 seconds.
Phase A. Thread 6 was ordered to sleep for 3 seconds.
Phase A. Thread 1 was ordered to sleep for 3 seconds.
Phase A. Thread 4 was ordered to sleep for 3 seconds.
Phase A. Thread 0 was ordered to sleep for 4 seconds.
Phase A. Thread 9 was ordered to sleep for 4 seconds.
Phase A. Thread 2 was ordered to sleep for 4 seconds.
Phase A. Thread 7 was ordered to sleep for 4 seconds.
Phase A. Thread 5 was ordered to sleep for 4 seconds.
Phase A. Thread 8 was ordered to sleep for 5 seconds.
Phase B. Thread 8 woke up.
Phase B. Thread 6 woke up.
Phase B. Thread 9 woke up.
Phase B. Thread 2 woke up.
Phase B. Thread 1 woke up.
Phase B. Thread 0 woke up.
Phase B. Thread 7 woke up.
Phase B. Thread 5 woke up.
Phase B. Thread 3 woke up.
Phase B. Thread 4 woke up.
*/