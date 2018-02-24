#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include "collatz.h"

// make
// make run
int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  assert(n > 0);

  pid_t pid = fork();
  if (pid == 0) {
    wait(NULL);
    collatz(n + 1);
  } else {
    collatz(n);
  }
  return 0;
}