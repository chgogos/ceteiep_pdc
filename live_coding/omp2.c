#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc!=3){
        printf("wrong number of arguments\n");
        exit(-1);
    }
    long long x = atoll(argv[1]);
    int threads = atoi(argv[2]);
    printf("Numbers: %lld Threads: %d\n", x, threads);

    long long sum = 0;
    #pragma omp parallel for num_threads(threads) reduction(+:sum)
    for(long long i =1;i<=x;i++){
        sum += i;
    }

    printf("The total sum is %lld\n", sum);
}