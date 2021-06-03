#include <stdio.h>
#include <unistd.h> // access to the POSIX operating system API

int main()
{
    for(int i=0;i<5;i++)
        fork();
    printf("%d\n", getpid()); // 2^5=32 processes
}