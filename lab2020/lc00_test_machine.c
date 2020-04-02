#include <stdio.h>
#include <stdint.h>

int main() {
    printf("size of int = %d\n", sizeof(int));
    printf("size of long = %d\n", sizeof(long));
    printf("size of long long= %d\n", sizeof(long long));
    printf("size of void = %d\n", sizeof(void));
    printf("size of void*= %d\n", sizeof(void*));
    printf("size of intptr_t= %d\n", sizeof(intptr_t));

    #ifdef __clang_major__
    printf ("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
    #endif

    #ifdef __GNUC__
    printf ("gcc detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
    #endif

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
size of long long= 8
size of void = 1
size of void*= 8
size of intptr_t= 8
gcc detected version 8.1
*/