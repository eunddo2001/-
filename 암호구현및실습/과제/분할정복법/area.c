#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int h[] = {0};

int Area(int start, int end)
{
    if (start == end)
        return h[start];
    int m = (start + end) / 2;
    int area = h[m];
    int l = m - 1;
    int r = m + 1;
    int height = h[m];
    while (start <= l || r <= end)
    {
        if (h[l] > h[r])
        {
            height = MIN(height, h[l]);
            l--;
        }
        else if (h[l] <= h[r])
        {
            height = MIN(height, h[r]);
            r++;
        }
        else if (l < start)
        {
            height = MIN(height, h[r]);
            r++;
        }
        else
        {
            height = MIN(height, h[l]);
            l--;
        }
        area = MAX(area, (r - l - 1) * height);
        // printf("%d\n", area);
    }
    return MAX(area, MAX(Area(start, m), Area(m + 1, end)));
}

int main(void)
{
    int n = 0;
    int result = 0;
    printf("Number of stick is: ");
    scanf("%d", &n);
    printf("Height of each stick is: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
    }
    result = Area(0, n - 1);
    printf("Result is: %d\n", result);
    return 0;
}