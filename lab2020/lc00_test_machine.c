#include "timer.h"
#include <stdio.h>
#include <stdlib.h> // RAND_MAX
#include <stdint.h>
#include <pthread.h>
#include <limits.h>

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

    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MIN = %d\n", INT_MIN);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LONG_MIN = %ld\n", LONG_MIN);
    printf("ULONG_MAX = %lu\n", ULONG_MAX);
    printf("ULLONG_MAX = %llu\n", ULLONG_MAX);

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
    printf("Spawn %d threads: %e\n", T, elapsed);
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
INT_MAX = 2147483647
INT_MIN = -2147483648
LONG_MAX = 2147483647
LONG_MIN = -2147483648
ULONG_MAX = 4294967295
ULLONG_MAX = 18446744073709551615
gcc detected version 8.1
Spawn 100 threads: 4.999876e-003
*/

/*
#############################################
OS: WSL on Windows 10 (Ubuntu 18.04.1)
CPU: Intel Core i7 7700K
RAM: 16GB
Cores/Threads: 4/8
C compiler: gcc (Ubuntu 9.2.1-17ubuntu1~18.04.1) 9.2.1 20191102
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
INT_MAX = 2147483647
INT_MIN = -2147483648
LONG_MAX = 9223372036854775807
LONG_MIN = -9223372036854775808
ULONG_MAX = 18446744073709551615
ULLONG_MAX = 18446744073709551615
gcc detected version 9.2
Time elapsed for spawning 100 threads: 8.327961e-03
*/

/*
#############################################
OS: macOS Catalina
CPU: 2.9 GHz Dual-Core Intel Core i7
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
INT_MAX = 2147483647
INT_MIN = -2147483648
LONG_MAX = 9223372036854775807
LONG_MIN = -9223372036854775808
ULONG_MAX = 18446744073709551615
ULLONG_MAX = 18446744073709551615
clang detected version 11.0
gcc detected version 4.2
Spawn 100 threads: 2.559900e-03
*/