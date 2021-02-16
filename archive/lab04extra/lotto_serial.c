// https://pastebin.com/qY4U4WDj
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

    for (int i = 0; i < MARKS + 1; i++)
        printf("Found %d lucky numbers by %d columns\n", i, results[i]);
    printf("Time elapsed = %.2f\n", cpu_time_used);

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
24 50 28 5 16 41 
Finished generating data after 10.58 seconds. Start counting...
Found 0 lucky numbers by 44430678 columns
Found 1 lucky numbers by 40999524 columns
Found 2 lucky numbers by 12812294 columns
Found 3 lucky numbers by 1666010 columns
Found 4 lucky numbers by 89768 columns
Found 5 lucky numbers by 1722 columns
Found 6 lucky numbers by 4 columns
Time elapsed = 6.81
*/


/*
##############################################
CPU: Intel Core i7 @ 2.9 GHz           (2C/4T)
RAM: 8GB
----------------------------------------------
macOS Catalina
##############################################
35 42 29 7 17 24 
Finished generating data after 11.19 seconds. Start counting...
Found 0 lucky numbers by 44416038 columns
Found 1 lucky numbers by 41006598 columns
Found 2 lucky numbers by 12817590 columns
Found 3 lucky numbers by 1668890 columns
Found 4 lucky numbers by 89205 columns
Found 5 lucky numbers by 1672 columns
Found 6 lucky numbers by 7 columns
Time elapsed = 15.43
*/