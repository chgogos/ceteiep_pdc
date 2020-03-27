#include <stdio.h>

int main() {
    printf("size of int = %d\n", sizeof(int));
    printf("size of long = %d\n", sizeof(long));
    printf("size of long long= %d\n", sizeof(long long));
    printf("size of void = %d\n", sizeof(void));
    printf("size of void*= %d\n", sizeof(void*));

    #ifdef __clang_major__
    printf ("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
    #endif

    #ifdef __GNUC__
    printf ("gcc detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
    #endif

}