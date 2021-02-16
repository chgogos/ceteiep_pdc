#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("wrong number of arguments, usage: %s <value>\n", argv[0]);
    exit(-1);
  }
  long long i, upto, sum;
  upto = atoll(argv[1]);
  sum = 0;
  for (i = 0; i <= upto; i++) {
    sum += i;
  }
  printf("The sum is %lld\n", sum);
  return 0;
}
