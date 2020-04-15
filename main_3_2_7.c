#include "stdio.h"

long long bad(int n)
{
    long i;
    long long a;
    long long b;
    long long tmp;


    a = 1;
    b = 0;
    while (n--)
    {
        tmp = a;
        a = 3 * a - b;
        b = tmp;
    }
    return (a);
}

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%lld\n", bad(n));
    return (0);
}