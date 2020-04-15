#include "stdio.h"
#define MAXN 1000005

int calc(long long n)
{
    long long a[MAXN];
    long long i;

    a[1] = 0;
    i = 1;
    while (++i <= n) 
        a[i] = MAXN;
    i = 1;
    while (++i <= n) 
    {
        if (a[i] > a[i - 1] + 1)
            a[i] = a[i - 1] + 1;
        if (i % 2 == 0)
        {
            if (a[i] > a[i / 2] + 1)
                a[i] = a[i / 2] + 1;
        }
        if (i % 3 == 0)
        {
            if (a[i] > a[i / 3] + 1)
                a[i] = a[i / 3] + 1;
        }
    }
    return (a[n]);
}

int main(void)
{
    long long n;
    int i;
    long long tmp;

    scanf("%lld", &n);
    printf("%d\n", calc(n));
    return (0);
}