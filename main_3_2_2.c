#include "stdio.h"
#define MAXN 100005

long long f_max(long long a, long long b, long long c)
{
    if (a > b)
        return (a > c ? a : c);
    else 
        return (b > c ? b : c);
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
        if (i > 4)
            a[i]= f_max(a[i - 5], a[i - 3], a[i - 1]) + tmp;
        else if (i > 2)
            a[i]= f_max(a[i - 3], a[i - 3], a[i - 1]) + tmp;
        else 
            a[i]= a[i - 1] + tmp;
    }
    printf("%lld\n", a[i - 1]);
    return (0);
}