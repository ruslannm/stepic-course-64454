#include "stdio.h"
#define MAXN 100005

int maxn(int n, int k, unsigned long *a, unsigned long len)
{
    int ret;
    unsigned long current;
    int i;

    ret = 1;
    i = 0;
    current = a[i];
    while (++i < n)
    {
        if (a[i] - current > len)
        {
            current = a[i];
            k--;
            if (1 == k)
                break ;
        }
    }
    if (ret && 1 == k)
        return (1);
    else
        return (0);
}

int main(void)
{
    int n;
    int k;
    int i;
    unsigned long a[MAXN];
    unsigned long l;
    unsigned long r;
    unsigned long mid;

    scanf("%d %d", &n, &k);
    i = 0;
    while (i < n)
        scanf("%lu", &a[i++]);
    l = 0;
    r = a[n - 1];
    while (l + 1 < r)
    {
        mid = (l + r) / 2;
        if (maxn(n, k, a, mid))
             l = mid;
            else
               r = mid;
    }
    printf("%lu\n", r);
    return (0);
}
