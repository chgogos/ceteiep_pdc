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
    printf("size of void               = %d bytes\n", sizeof(void));
    printf("size of char               = %d bytes\n", sizeof(char));
    printf("size of short              = %d bytes\n", sizeof(short));
    printf("size of int                = %d bytes\n", sizeof(int));
    printf("size of long               = %d bytes\n", sizeof(long));
    printf("size of long long          = %d bytes\n", sizeof(long long));
    printf("size of unsigned long long = %d bytes\n", sizeof(long long));
    printf("size of intptr_t           = %d bytes\n", sizeof(intptr_t));
    printf("size of int*               = %d bytes\n", sizeof(int *));
    printf("size of void*              = %d bytes\n", sizeof(void *));
    printf("RAND_MAX   = %d\n", RAND_MAX);
    printf("INT_MAX    = %d\n", INT_MAX);
    printf("INT_MIN    = %d\n", INT_MIN);
    printf("LONG_MAX   = %ld\n", LONG_MAX);
    printf("LONG_MIN   = %ld\n", LONG_MIN);
    printf("ULONG_MAX  = %lu\n", ULONG_MAX);
    printf("ULLONG_MAX = %llu\n", ULLONG_MAX);

#ifdef _WIN32
    printf("Windows detected\n");
#endif
#ifdef __linux__
    printf("Linux detected\n");
#endif
#ifdef __APPLE__
    printf("OSX detected\n");
#endif

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
    printf("Time for spawning %d threads: %e\n", T, elapsed);
}
