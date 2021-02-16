#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 25

int main() {
  char write_msg[BUFFER_SIZE] = "Greetings";
  char read_msg[BUFFER_SIZE];
  int fd[2];
  pipe(fd);
  pid_t pid = fork();
  if (pid < 0) {
    fprintf(stderr, "Fork failed");
    exit(-1);
  }
  if (pid > 0) {  // parent process
    close(fd[0]);
    write(fd[1], write_msg, strlen(write_msg) + 1);
    close(fd[1]);
  } else {        // child process
    close(fd[1]);
    read(fd[0], read_msg, BUFFER_SIZE);
    printf("child process got data %s from parent process\n", read_msg);
    close(fd[0]);
  }
  return 0;
}