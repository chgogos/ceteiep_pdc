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


/*
##############################################
CPU: Intel Core i7-7700K @ 4.2GHz  (4C/8T)
RAM: 32GB DDR4
----------------------------------------------
Windows 10
##############################################
38 8 34 3 27 35
Finished generating data after 10.32 seconds. Start counting...
Time elapsed = 6.73
Found 0 lucky numbers by 44428727 columns
Found 1 lucky numbers by 41003421 columns
Found 2 lucky numbers by 12811176 columns
Found 3 lucky numbers by 1665487 columns
Found 4 lucky numbers by 89540 columns
Found 5 lucky numbers by 1641 columns
Found 6 lucky numbers by 8 columns
OpenMP
Found 0 lucky numbers by 44428727 columns
Found 1 lucky numbers by 41003421 columns
Found 2 lucky numbers by 12811176 columns
Found 3 lucky numbers by 1665487 columns
Found 4 lucky numbers by 89540 columns
Found 5 lucky numbers by 1641 columns
Found 6 lucky numbers by 8 columns
Time elapsed = 1.69
*/

/*
##############################################
CPU: Intel Core i7 @ 2.9 GHz           (2C/4T)
RAM: 8GB
----------------------------------------------
macOS Catalina
##############################################
34 30 10 48 47 12 
Finished generating data after 10.30 seconds. Start counting...
Time elapsed = 10.92
Found 0 lucky numbers by 44425451 columns
Found 1 lucky numbers by 41005386 columns
Found 2 lucky numbers by 12811160 columns
Found 3 lucky numbers by 1667055 columns
Found 4 lucky numbers by 89245 columns
Found 5 lucky numbers by 1696 columns
Found 6 lucky numbers by 7 columns
OpenMP
Found 0 lucky numbers by 44425451 columns
Found 1 lucky numbers by 41005386 columns
Found 2 lucky numbers by 12811160 columns
Found 3 lucky numbers by 1667055 columns
Found 4 lucky numbers by 89245 columns
Found 5 lucky numbers by 1696 columns
Found 6 lucky numbers by 7 columns
Time elapsed = 4.90
*/