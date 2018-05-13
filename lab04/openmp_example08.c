#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N 1 << 10

int main(){
	int sum =0;
	int A[N];
	srand(1729);
	for(int i=0;i<N;i++){
		A[i] = rand() % 10;
	}

	#pragma omp parallel for reduction(+ : sum)
		for (int i=0;i<N;i++){
			sum += A[i];
		}

	printf("The sum is %d\n", sum);
}
