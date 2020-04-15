#include "stdio.h"

float f(int n, int *a, long double x)
{
    long double ax[6];
    long double tmp;
    int i;

    i = 1;
    tmp = x;
    while (i <= n)
    {
        ax[i] = (a[i] ? a[i] * tmp : 0);
        tmp = tmp * x;
        i++;
    }
    while (i <= 5)
        ax[i++] = 0;
    return (a[0] + ax[1] + ax[2] + ax[3] + ax[4] + ax[5]);
}

int main(void)
{
    int n;
    int k;
    int i;
    long double l;
    long double r;
    long double mid;
    int a[6];

    scanf("%d", &n);
    i = n;
    while (i >= 0)
    {
        scanf("%d", &k);
        a[i--] =  k;
    }
    i = n;
    while (++i <= 5)
    {
        a[i] =  0;
    }
    l = -100.0;
    r = 100.0;
    i = 0;
    while (i < 100)
    {
        mid = (l + r) / 2;
        if (f(n, a, mid) < 0.0)
            l = mid;
        else
            r = mid;
        i++;
    }
    printf("%.16Lf\n", r);
//    printf("%.16Lf\n", (r + l) / 2);
    return (0);
}
