#include "timer.h"
#include <stdio.h>
#include <stdlib.h> // RAND_MAX
#include <stdint.h>
#include <pthread.h>

#define T 100

void *dummy(void *arg)
{
    // DO NOTHING
    return NULL;
}

int main()
{
    printf("size of int = %lu\n", sizeof(int));
    printf("size of long = %lu\n", sizeof(long));
    printf("size of long long = %lu\n", sizeof(long long));
    printf("size of void = %lu\n", sizeof(void));
    printf("size of void* = %lu\n", sizeof(void *));
    printf("size of intptr_t = %lu\n", sizeof(intptr_t));
    printf("RAND_MAX = %d\n", RAND_MAX);

#ifdef __clang_major__
    printf("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
#endif

#ifdef __GNUC__
    printf("gcc detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif

    double start, finish, elapsed;
    GET_TIME(start);

    pthread_t threads[T];
    for (int i = 0; i < T; i++)
        pthread_create(&threads[i], NULL, dummy, NULL);

    for (int i = 0; i < T; i++)
        pthread_join(threads[i], NULL);

    GET_TIME(finish);
    elapsed = finish - start;
    printf("Time elapsed for spawning %d threads: %e\n", T, elapsed);
}

/*
#############################################
OS: Windows 10
CPU: Intel Core i7 7700K
RAM: 16GB
Cores/Threads: 4/8
C compiler: gcc (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
#############################################
έξοδος:
#############################################
size of int = 4
size of long = 4
size of long long = 8
size of void = 1
size of void* = 8
size of intptr_t = 8
RAND_MAX = 32767
clang detected version 11.0
*/

/*
#############################################
OS: macOS Catalina
CPU: 2,9 GHz Dual-Core Intel Core i7
RAM: 8GB
Cores/Threads: 2/4
C compiler: Apple clang version 11.0.0 (clang-1100.0.33.16)
#############################################
έξοδος:
#############################################
size of int = 4
size of long = 8
size of long long = 8
size of void = 1
size of void* = 8
size of intptr_t = 8
RAND_MAX = 2147483647
clang detected version 11.0
gcc detected version 4.2
*/