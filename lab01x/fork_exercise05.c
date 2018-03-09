#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("wrong number of arguments, usage: %s <value>\n", argv[0]);
		exit(-1);
	}
	pid_t chid = fork();
	if (chid == 0) {
		int x = atoi(argv[1]) % 2;
		exit(x);
	}
	int rv;
	pid_t childid = wait(&rv);
	printf("Parent got value %d from child with id %d\n", WEXITSTATUS(rv), childid);
}
