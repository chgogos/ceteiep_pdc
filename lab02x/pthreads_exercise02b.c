#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
int thread_num;
ll x;
ll sum = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_work(void *tid) {
  long mytid = (long)tid;
  ll mysum = 0;
  ll stride = x / thread_num;
  ll left = mytid * stride + 1;
  ll right = mytid * stride + stride;
  if (right > x)
    right = x;
  for (ll i = left; i <= right; i++)
    mysum += i;
  printf("sum computed by thread %ld is %lld\n", mytid, mysum);
  pthread_mutex_lock(&lock);
  sum += mysum;
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main(int argc, char *argv[]) {
  x = atoll(argv[1]);
  thread_num = atoi(argv[2]);
  pthread_t threads[thread_num];
  for (long t = 0; t < thread_num; t++)
    pthread_create(&threads[t], NULL, thread_work, (void *)t);

  for (long t = 0; t < thread_num; t++)
    pthread_join(threads[t], NULL);
  printf("The total sum is %lld\n", sum);
  return 0;
}