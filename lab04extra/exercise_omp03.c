/*
Να γεμίζει πίνακα με 1.000.000 ακέραιες τιμές στο διάστημα [1,5]. 
Να εμφανίζει τον πίνακα συχνοτήτων.
*/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main()
{
    int a[N];
    // srand(time(NULL));
    srand(42);
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 5 + 1;
    }

    int f[5] = {0, 0, 0, 0, 0};
#pragma omp parallel for num_threads(4) reduction(+ \
                                                  : f)
    for (int i = 0; i < N; i++)
    {
        int k = a[i] - 1;
        f[k]++;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d stars were given by %d.\n", i + 1, f[i]);
    }
    return 0;
}