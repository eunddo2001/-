#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *px, int *py)
{
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

void main()
{
    int *a;
    a = (int *)malloc(6 * sizeof(int));

    for (int i = 0; i < 6; ++i)
    {
        a[i] = i;
    }

    for (int i = 0; i < 6; ++i)
    {
        printf("%d", a[i]);
    }
    printf("\n");

    swap(a, a + 1);

    for (int i = 0; i < 6; ++i)
    {
        printf("%d", a[i]);
    }
}