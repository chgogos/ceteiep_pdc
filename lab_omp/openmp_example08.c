#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N 1 << 10

// άθροισμα στοιχείων πίνακα 1024 θέσεων με τυχαίες τιμές 
int main() {
	int i;
	int sum = 0;
	int A[N];
	srand(1729);
	for (i = 0; i < N; i++) {
		A[i] = rand() % 10;
	}

	// serial
	for (i = 0; i < N; i++) {
		sum += A[i];
	}
	printf("The sum is %d\n", sum);

	// parallel
	sum = 0;
	#pragma omp parallel for reduction(+ : sum)
	for (i = 0; i < N; i++) {
		sum += A[i];
	}

	printf("The sum is %d\n", sum);
	return 0;
}
