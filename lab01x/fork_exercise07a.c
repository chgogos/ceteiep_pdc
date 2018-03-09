#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define r 10.0

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("wrong number of arguments, Usage: <exe> <number_of_points>\n");
		exit(-1);
	}

	int points = atoi(argv[1]);
	srand(time(NULL));
	int c = 0;
	for (int i = 0; i < points; i++) {
		double x = (double) rand() / RAND_MAX * 2 * r - r;
		double y = (double) rand() / RAND_MAX * 2 * r - r;
		double d = sqrt(x * x + y * y);
		if (d < r)
			c++;
		// printf("%.2f, %.2f %.2f\n", x,y,d);
	}
	double pi = (double)c / (double)points * 4;
	printf("PI estimation %f  vs %f\n", pi, M_PI);

	return 0;
}