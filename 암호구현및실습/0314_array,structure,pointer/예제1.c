#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int b[3][4];
    int k = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            b[i][j] = k++;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            printf("%d", b[i][j]);
        }
        printf("\n");
    }
}