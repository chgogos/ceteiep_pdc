#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t chid = fork();
	if (chid == 0) {
		printf("Child process\n");
		execl("/bin/ls", "ls", NULL, NULL);
	} else {
		printf("Parent process\n");
		wait(NULL);
	}
	return 0;
}
