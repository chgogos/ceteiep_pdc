#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int fd[2];
	pipe(fd);
	pid_t chid = fork();
	if (chid == 0) {
		int sum = 0;
		for (int i = 101; i <= 200; i++)
			sum += i;
		printf("Computed sum by child process is %d\n", sum);
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	} else {
		int sum = 0;
		for (int i = 1; i <= 100; i++)
			sum += i;
		printf("Computed sum by parent process is %d\n", sum);
		int val;
		close(fd[1]);
		read(fd[0], &val, sizeof(val));
		close(fd[0]);
		printf("Parent receives value %d from child\n", val);
		printf("The total sum is %d\n", sum + val);
	}
	return 0;
}