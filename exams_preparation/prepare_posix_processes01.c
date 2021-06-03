#include <stdio.h>
#include <unistd.h> // access to the POSIX operating system API
#include <sys/wait.h>

int main()
{
    int x = 1;
    printf("The fork will occur in 5 seconds\n");
    sleep(5); // περιμένει 5 δευτερόλεπτα
    pid_t pid = fork();
    if (pid == 0)
    {
        x = 2;
        printf("Child process %d, my parent is process %d, x = %d\n",
               getpid(), getppid(), x);
    }
    else
    {
        x = 3;
        printf("Parent process %d, my parent is process %d, my child is %d, x = %d\n",
               getpid(), getppid(), pid, x);
        wait(NULL); // η διεργασία γονέας περιμένει έτσι ώστε να τελειώσει η διεργασία παιδί
    }
    printf("x=%d\n", x);
}