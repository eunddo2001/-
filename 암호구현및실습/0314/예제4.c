#include <stdio.h>

int y = 0;
int z = 0;

void bar(int **ptr)
{
    *ptr = &z;
}

void foo(void)
{
    int *x = &y;
    bar(&x);

    *x = 100;

    printf("y=%d, z=%d\n", y, z);
}

int main(void)
{
    foo();
    return 0;
}