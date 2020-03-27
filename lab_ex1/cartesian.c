#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000      // αριθμός σημείων στο καρτεσιανό επίπεδο
#define DISTANCE 0.1 // απόσταση σημείων

struct point
{
    double x, y;
};

int main()
{
    int counter = 0;
    long seed = 1821L; // time(NULL)
    srand(seed);
    struct point points[N];
    for (int i = 0; i < N; i++)
    {
        points[i].x = (double)rand() / RAND_MAX * 2.0 - 1.0;
        points[i].y = (double)rand() / RAND_MAX * 2.0 - 1.0;
    }

    // η εργασία γίνεται εδώ
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            double x = points[i].x - points[j].x;
            double y = points[i].y - points[j].y;
            if (sqrt(pow(x, 2) + pow(y, 2)) < DISTANCE)
                counter++;
        }
    
    printf("Number of points: %d\n", counter);
}

/* έξοδος
Number of points: 377905
*/