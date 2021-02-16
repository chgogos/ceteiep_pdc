#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
	int x = 5;
	printf("A. value of x is %d\n", x);
	pid_t chid = fork();
	if (chid == 0) {
		x++;
		printf("B. value of x is %d\n", x);
	} else {
		x--;
		printf("C. value of x is %d\n", x);
	}
	printf("D. value of x is %d\n", x);
	return 0;
}
