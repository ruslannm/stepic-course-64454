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

int f_abs(int a)
{
    return (a < 0 ? -a : a);
}

int main(void)
{
    int a;
    int b;
    int c;
    int nod;

    scanf("%d %d %d", &a, &b, &c);
    nod = gcd(f_abs(a), f_abs(b));
    if (0 == c % nod)
        printf("%d\n", 1);
    else
        printf("%d\n", 0);
    return (0);
}
