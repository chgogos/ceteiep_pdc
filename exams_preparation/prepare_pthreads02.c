// ΠΡΟΟΔΟΣ 27/4/2018 ΘΕΜΑ 2

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define T 10
#define N 1000000
#define M 100

int a[N];
int frequency[M];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_counter(void *tid) {
    long mytid = (long)tid;
    int local_freq[M];
    for(int i=0;i<M;i++){
        local_freq[i]=0;
    }
    for(int i= mytid * N/T;i<(mytid+1)*N/T;i++){
        local_freq[a[i]]++;
    }
    pthread_mutex_lock(&lock);
    for(int i=0;i<M;i++){
        frequency[i]+=local_freq[i];
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
  pthread_t threads[T];
  srand(1729);
  
  for (int i = 0; i < N; i++) {
    a[i] = random() % M;
  }
  
  for(long t=0;t<T;t++){
      pthread_create(&threads[t], NULL, thread_counter, (void*)t);
  }

  for(long t=0;t<T;t++){
      pthread_join(threads[t], NULL);
  }

  for(int i=0;i<M;i++){
      printf("%d -> %d\n", i, frequency[i]);
  }
}
