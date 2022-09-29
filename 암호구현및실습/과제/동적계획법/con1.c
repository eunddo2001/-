#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int n;

void getMaxElement(int seq[]) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (seq[i] > max)
            max = seq[i];
    }
    printf("%d", max);
}

void getMaxArr(int seq[]) {
    int temp = 0;
    int max = 0;
    int lindex = n;
    int rindex = 0;
    int llindex = 0;
    for (int i = 0; i < n; i++) {
        temp += seq[i];
        if (temp > max) {
            max = temp;
            rindex = i;
            lindex = llindex+1;
        }
        else if (temp < 0) {
            temp = 0;
            llindex = i;
        }
    }

    if (lindex == n)
        getMaxElement(seq);
    else {
        for (int i = lindex; i <= rindex; i++) {
            printf("%d ", seq[i]);
        }
    }
}

int main(void)
{
    printf("원소 개수: ");
    scanf("%d", &n);
    int seq[100] = { 0 };
    printf("%d개의 실수: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &seq[i]);
    }
    printf("%d개의 연속된 원소의 합이 최대가 되는 원소: ", n);
    getMaxArr(seq);

    return 0;
}