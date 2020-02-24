/*
 * Υπολογισμός του πλήθους των πρώτων ακεραίων μέχρι και τον ακέραιο finish
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(long x)
{
    long limit = (long)sqrt(x);
    for (long i = 2; i <= limit; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    long finish = 4000000;
    long p_count = 1;
    long next_candidate = 3;

    while (next_candidate < finish)
    {
        if (is_prime(next_candidate))
            p_count++;
        next_candidate += 2;
    }
    printf("Number of primes = %ld\n", p_count);
}
