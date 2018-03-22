// busy wait example (order termination of each thread)
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> // sleep

#define N 5

int sleep_times[N];
long turn = 0;

void* work(void* rank) {
	long my_rank = (long)rank;
	printf("Thread %ld will sleep for %d seconds\n", my_rank, sleep_times[my_rank]);
	sleep(sleep_times[my_rank]);
	printf("Thread %ld woke up after %d seconds (waiting its turn)\n", my_rank, sleep_times[my_rank]);
	while (turn != my_rank);
	turn++;
	printf("Thread %ld says hi!!!\n", my_rank);
	return NULL;
}

int main() {
	srand(time(NULL));
	for (int i = 0; i < N; i++)
		sleep_times[i] = rand() % 10 + 1;
	pthread_t th[N];
	for (long t = 0; t < N; t++)
		pthread_create(&th[t], NULL, work, (void*)t);

	for (long t = 0; t < N; t++)
		pthread_join(th[t], NULL);
	return 0;
}
