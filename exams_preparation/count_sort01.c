#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
    int N = 10000;
    if (argc > 1)
        N = atoi(argv[1]);
    int *a = (int *)malloc(sizeof(int) * N);
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        a[i] = rand() % 2;

    // κώδικας που ζητείται να παραλληλοποιηθεί (αρχή)
    int c = 0;
    for (int i = 0; i < N; i++)
        if (a[i] == 0)
            c++;
    // κώδικας που ζητείται να παραλληλοποιηθεί (τέλος)

    for (int i = 0; i < N; i++)
        if (i < c)
            a[i] = 0;
        else
            a[i] = 1;
    printf("The last 0 is at position %d\n", c - 1);
    free(a);
}

/*
The last 0 is at position 5048
*/