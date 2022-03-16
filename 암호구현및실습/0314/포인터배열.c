#include <stdio.h>

int main(void)
{
    char A[][7] = {"ABC", "DEFG", "HIJKL"};
    char *pA[3] = {A[0], A[1], A[2]};
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("pA --> %s\n", pA[i]);
    }
    return 0;
}