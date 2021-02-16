#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("wrong number of arguments, usage: <exe> <upto>\n");
    exit(-1);
  }
  long long i, upto = atoll(argv[1]), sum = 0;
  int fd[2];
  pipe(fd);
  pid_t chid = fork();
  if (chid == 0) {
    for (i = 0; i <= upto / 2; i++) {
      sum += i;
    }
    close(fd[0]);
    write(fd[1], &sum, sizeof(sum));
    close(fd[1]);
  } else {
    for (i = upto / 2 + 1; i <= upto; i++) {
      sum += i;
    }
    wait(NULL);
    long long sum_child;
    close(fd[1]);
    read(fd[0], &sum_child, sizeof(sum_child));
    close(fd[0]);
    printf("The sum is %lld\n", sum + sum_child);
  }
  return 0;
}