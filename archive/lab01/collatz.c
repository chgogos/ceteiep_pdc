#include <stdio.h>

void collatz(int n) {
	printf("Collatz sequence for %d: ", n);
	while (n != 1) {
		if (n % 2 == 0)
			n = n / 2;
		else
			n = 3 * n + 1;
		printf("%d ", n);
	}
	printf("\n");
}
