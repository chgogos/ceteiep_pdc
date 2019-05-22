#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNS_PLAYED 100000000 // αριθμός στηλών που παίχθηκαν
#define BALLOTS 50               // αριθμοί που μπορούν να επιλεγούν (π.χ. 1 έως 50)
#define MARKS 6                  // αριθμοί που συμπληρώνει ο παίκτης

void random_column(int rc[])
{
    int c = 0;
    while (c < MARKS)
    {
        int picked = rand() % BALLOTS + 1;
        int found = 0;
        for (int i = 0; i < c; i++)
            if (rc[i] == picked)
                found = 1;
        if (!found)
        {
            rc[c] = picked;
            c++;
        }
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    srand(time(NULL));
    int *played = (int *)malloc(sizeof(int) * COLUMNS_PLAYED * MARKS);

    int winning_column[MARKS];
    random_column(winning_column);
    for (int i = 0; i < MARKS; i++)
        printf("%d ", winning_column[i]);
    printf("\n");

    for (int i = 0; i < COLUMNS_PLAYED; i++)
    {
        int rc[MARKS];
        random_column(rc);
        for (int j = 0; j < 6; j++)
            played[i * 6 + j] = rc[j];
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Finished generating data after %.2f seconds. Start counting...\n", cpu_time_used);

    start = clock();
    int results[MARKS + 1] = {0};
    for (int i = 0; i < COLUMNS_PLAYED; i++)
    {
        int c = 0;
        for (int j = 0; j < MARKS; j++)
            for (int k = 0; k < MARKS; k++)
                if (played[i * MARKS + j] == winning_column[k])
                    c++;
        results[c]++;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time elapsed = %.2f\n", cpu_time_used);

    for (int i = 0; i < MARKS + 1; i++)
        printf("Found %d lucky numbers by %d columns\n", i, results[i]);

    // ###################################################################
    printf("OpenMP\n");
    double start_d = omp_get_wtime();
    int results_OMP[MARKS + 1] = {0};
#pragma omp parallel for reduction(+ \
                                   : results_OMP)
    for (int i = 0; i < COLUMNS_PLAYED; i++)
    {
        int c = 0;
        for (int j = 0; j < MARKS; j++)
            for (int k = 0; k < MARKS; k++)
                if (played[i * MARKS + j] == winning_column[k])
                    c++;
        results_OMP[c]++;
    }
    double end_d = omp_get_wtime();

    for (int i = 0; i < MARKS + 1; i++)
        printf("Found %d lucky numbers by %d columns\n", i, results_OMP[i]);
    printf("Time elapsed = %.2f\n", end_d - start_d);
    // ###################################################################

    free(played);
    return 0;
}
