#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int x = 5;
	printf("A. value of x is %d\n", x);
	pid_t chid = fork();
	printf("B. value of x is %d\n", x);
	if (chid == 0) {
		x++;
		printf("C. child process %d having parent %d, value of x is %d\n",
		       getpid(), getppid(), x);
		sleep(2);
		execl("/bin/echo", "echo", "hello", NULL);
	} else {
		x--;
		printf("D. parent process %d with child %d, value of x is %d\n",
		       getpid(), chid, x);
		wait(NULL);
	}
	printf("E. value of x is %d\n", x);
	return 0;
}
