#include <stdio.h>

void fun(void *x)
{
    printf("%d\n", *((int *)x));
}

int main()
{
    printf("Test 1\n");
    for (long i = 0; i < 5; i++)
    {
        void *vp = (void *)i;
        printf("%ld\n", (long)vp);
    }

    printf("Test 2\n");
    for (int i = 0; i < 5; i++)
    {
        void *vp = &i;
        printf("%d\n", *((int *)vp));
    }

    printf("Test 3\n");
    for (int i = 0; i < 5; i++)
    {
        fun(&i);
    }

}