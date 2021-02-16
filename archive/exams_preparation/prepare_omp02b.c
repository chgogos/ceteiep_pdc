/*
Δέχεται ως όρισμα γραμμής εντολών έναν ακέραιο αριθμό x και 
εμφανίζει το άθροισμα των ριζών όλων των ακεραίων από το 1 μέχρι το x
*/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);
    double sum = 0.0;

#pragma omp parallel num_threads(10)
    {
        int t_id = omp_get_thread_num();
        int T = omp_get_num_threads();
        int from = t_id * x / T + 1;
        int to = (t_id + 1) * x / T;
        printf("Thread %d: compute from %d to %d\n", t_id, from, to);
        for (int i = from; i <= to; i++)
        {
#pragma omp critical
            sum += sqrt(i);
        }
    }
    printf("Sum is %.2f\n", sum);

    return 0;
}

/*
$ ./a.out 1000
Thread 5: compute from 501 to 600
Thread 4: compute from 401 to 500
Thread 0: compute from 1 to 100
Thread 2: compute from 201 to 300
Thread 8: compute from 801 to 900
Thread 1: compute from 101 to 200
Thread 3: compute from 301 to 400
Thread 6: compute from 601 to 700
Thread 7: compute from 701 to 800
Thread 9: compute from 901 to 1000
Sum is 21097.46
*/