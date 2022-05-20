#include <stdio.h>

int Sum(int n)
{
    if (n == 1)
        return 1;
    if (n % 2 == 1)
        return Sum(n - 1) + n;
    else
        return 2 * Sum(n / 2) + (n / 2) * (n / 2);
}

int main(void)
{
    int n = 0;
    int result = 0;
    printf("n is : ");
    scanf("%d", &n);
    result = Sum(n);
    printf("Result is: %d\n", result);
    return 0;
}