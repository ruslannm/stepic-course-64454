#include "stdio.h"
#define MAXN 100005

long long f_max(long long a, long long b)
{
    return (a > b ? a : b);
}

int main(void)
{
    int n;
    int i;
    long long a[MAXN];
    long long tmp;

    scanf("%d", &n);
    i = 0;
    a[i++] = 0;
    scanf("%lld", &a[i]);
    while (++i <=n)
    {
        scanf("%lld", &tmp);
        a[i]= f_max(a[i - 2], a[i - 1]) + tmp;
    }
    printf("%lld\n", a[i - 1]);
    return (0);
}