#include <stdio.h>

int main()
{
    char A[][7] = {"ABC", "DEFG", "HIJKL"};
    char *pvar = A[0];
    char **pA;
    int i;
    pA = &pvar;
    for (i = 0; i < 3; i++)
    {
        printf("pA --> %s\n", *pA);
        pvar = A[i + 1];
    }
    return 0;
}