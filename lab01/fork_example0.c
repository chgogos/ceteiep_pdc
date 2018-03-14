#include <stdio.h>
#include <unistd.h>

int main() {
	int x = 5;
	printf("A. value of x is %d as reported by process:%d\n", x, getpid());
	pid_t chid = fork();
	if (chid == 0)
		x--;
	else
		x++;
	printf("B. value of x is %d as reported by process:%d\n", x, getpid());
	return 0;
}
