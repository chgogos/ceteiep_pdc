#include <stdio.h>
#include 
#define N 10000

int main()
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);
}