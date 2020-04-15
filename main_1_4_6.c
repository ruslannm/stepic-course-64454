#include "stdio.h"
#define MAXN 100005

unsigned long maxn(int n, int k, unsigned long *a, unsigned long len)
{
    unsigned long ret;
    unsigned long current;
    int i;

    ret = 0;
    i = 0;
    while (++i <= n)
    {
        ret = ret + a[i] / len;
        if (ret >= k)
            break ;
    }
    return (ret);
}

int main(void)
{
    int n;
    int k;
    int i;
    int issolve;
    unsigned long a[MAXN];
    unsigned long l;
    unsigned long r;
    unsigned long mid;
    unsigned long maxa;

    issolve = 0;
    scanf("%d %d", &n, &k);
    i = 0;
    maxa = 0;
    while (++i <= n)
    {
        scanf("%lu", &a[i]);
        if (a[i] > maxa)
            maxa = a[i];
    }
    l = 0;
    r = maxa + 1;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;
        
        if (maxn(n, k, a, mid) >= k)
        {
            l = mid;
            issolve = 1;
        }
        else
            r = mid;
    }
    printf("%lu\n", l * issolve);
    return (0);
}
