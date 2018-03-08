#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include "collatz.h"

int main(int argc, char **argv) {
  if (argc != 2){
    fprintf(stderr, "wrong number of arguments");
    exit(-1);
  }
  int n = atoi(argv[1]);
  assert(n > 0);
  pid_t pid = fork();
  if (pid == 0) {
    printf("Child process: ");
    collatz(n + 1);
  } else {
    printf("Parent process: ");
    collatz(n);
    wait(NULL);
  }
  return 0;
}
