#include <stdio.h>
#include <unistd.h> // POSIX API
#include <sys/wait.h>

int main()
{
    int x = 1;
    printf("Hello from %d\n", getpid());

    pid_t pid = fork();
    if (pid == 0) // κώδικας που θα εκτελέσει η διεργασία child
    {
        x++;
        printf("I am child %d and  my parent is %d \n", getpid(), getppid());
        sleep(10);
    }
    else // κώδικας που θα εκτελέσει η διεργασία parent
    {
        x--;
        printf("I am parent %d and my parent is %d and my child is %d\n", getpid(), getppid(), pid);
        wait(NULL);
        sleep(20);
    }

    // sleep(10);
    // printf("Bye");
}