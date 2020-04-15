#include "stdio.h"

long long fibo(int n)
{
    long i;
    long long ret[91];


    ret[0] = 1;
    ret[1] = 2;
    if (n < 2)
        return (ret[n]);
    i = 1;
    while (++i <= n)
        ret[i] = ret[i - 1] + ret[i - 2];
    return ret[i - 1];
}

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%lld\n", fibo(n));
    return (0);
}