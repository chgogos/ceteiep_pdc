#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define r 10.0

int count_points_inside_circle(int N) {
	int c = 0;
	for (int i = 0; i < N; i++) {
		double x = (double) rand() / RAND_MAX * 2 * r - r;
		double y = (double) rand() / RAND_MAX * 2 * r - r;
		double d = sqrt(x * x + y * y);
		if (d < r)
			c++;
	}
	return c;
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("wrong number of arguments, Usage: <exe> <number_of_points>\n");
		exit(-1);
	}
	int fd[2];
	pipe(fd);
	int points = atoi(argv[1]);
	pid_t chid = fork();
	if (chid == 0) {
		srand(time(NULL));
		int c1 = count_points_inside_circle(points / 2);
		close(fd[0]);
		write(fd[1], &c1, sizeof(c1));
		close(fd[1]);
	} else {
		srand(time(NULL));
		int c2 = count_points_inside_circle(points / 2);
		wait(NULL);
		int c1;
		close(fd[1]);
		read(fd[0], &c1, sizeof(c1));
		close(fd[0]);
		double pi = (double) (c1 + c2) / (double)points * 4;
		printf("PI estimation %f  vs %f\n", pi, M_PI);
	}
	return 0;
}
