#include "stdio.h"

long long mnorm(long long d, long long mod)
{
    return ((d % mod + mod) % mod);
}

long long msum(long long x, long long y, long long mod)
{
    return (mnorm((mnorm(x, mod) + mnorm(y, mod)) % mod, mod));
}

long long msub(long long x, long long y, long long mod)
{
    return (mnorm((mnorm(x, mod) - mnorm(y, mod)) % mod, mod));
}

long long madd(long long x, long long y, long long mod)
{
    return (mnorm((mnorm(x, mod) * mnorm(y, mod)) % mod, mod));
}

int gcd(int a, int b)
{
    if (b > a)
        return gcd(b, a);
    if (b == 0) 
        return (a);
    return gcd(b, mnorm(a, b));
}

int main(void)
{
    int a[100];
    int n;
    int i;
    int nod;

    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d", &a[i]);
    nod = gcd(a[0], a[1]);
    i = 1;
    while (++i < n)
        nod = gcd(nod, a[i]);
    printf("%d", nod);
    return (0);
}
