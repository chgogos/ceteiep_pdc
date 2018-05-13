#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
	int a = 0, b = 0;
	#pragma omp parallel num_threads(4) shared(a) firstprivate(b)
	{
		b++;
		int my_rank = omp_get_thread_num();
		#pragma omp critical
		a++;

		printf("%d a=%d b=%d\n", my_rank, a, b);
	}
	printf("a=%d b=%d\n", a, b);
	return 0;
}