#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define THREAD_COUNT 4

void *work(void *tid)
{
  // υποτίθεται ότι οι ακόλουθες τιμές υπολογίζονται με χρονοβόρα επεξεργασία εντός του κάθε thread
  // το thread 0 υπολογίζει την τιμή 23, το thread 1 την τιμή 12 κοκ
  long dummy_values[] = {23, 12, 78, 90};
  long mytid = (long)tid;
  long r = dummy_values[mytid];
  printf("Thread %ld produces %ld\n", mytid, r);
  pthread_exit((void *)r);
}

int main()
{
  long t;
  pthread_t thread_handles[THREAD_COUNT];
  for (t = 0; t < THREAD_COUNT; t++)
    pthread_create(&thread_handles[t], NULL, work, (void *)t);

  for (t = 0; t < THREAD_COUNT; t++)
  {
    void *r;
    pthread_join(thread_handles[t], &r);
    printf("Thread %ld returns %ld\n", t, (long)r);
  }
  return 0;
}