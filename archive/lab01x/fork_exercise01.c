#include <stdio.h>
#include <unistd.h>

int main() {
	fork();
	fork();
	printf("hello from process %d\n", getpid());
	return 0;
}