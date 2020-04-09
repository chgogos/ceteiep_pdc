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
#pragma omp parallel num_threads(100)
    {
        double local_sum = 0.0;
        for (int i = 1; i <= x; i++)
        {
            local_sum += sqrt(i);
        }
#pragma omp critical
        sum += local_sum;
    }
    printf("Sum is %.2f\n", sum);

    return 0;
}