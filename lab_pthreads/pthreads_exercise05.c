#include <stdio.h>
#include <pthread.h>

int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum = 0;
pthread_mutex_t mx;

void *thread1_work(void *arg) {
  int q = 0;
  for (int i = 0; i < 5; i++)
    q += A[i];
  pthread_mutex_lock(&mx);
  sum += q;
  pthread_mutex_unlock(&mx);
  return NULL;
}

void *thread2_work(void *arg) {
  int q = 0;
  for (int i = 5; i < 10; i++)
    q += A[i];
  pthread_mutex_lock(&mx);
  sum += q;
  pthread_mutex_unlock(&mx);
  return NULL;
}

int main() {
  pthread_t thread1, thread2;
  pthread_mutex_init(&mx, NULL);
  pthread_create(&thread1, NULL, thread1_work, NULL);
  pthread_create(&thread2, NULL, thread2_work, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  printf("the sum is %d\n", sum);
  pthread_mutex_destroy(&mx);
  return 0;
}
