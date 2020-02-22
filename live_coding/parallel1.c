#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 10000

int main()
{
    pid_t chid = fork();
    if (chid == 0)
    {
        int sum = 0;
        for (int i = 1; i <= N/2; i++)
        {
            sum += i;
        }
        printf("child process gives %d\n", sum);
    }
    else
    {
        int sum = 0;
        for (int i = N/2+1; i <= N; i++)
        {
            sum += i;
        }
        printf("parent process gives %d\n", sum);
        wait(NULL);
    }
}