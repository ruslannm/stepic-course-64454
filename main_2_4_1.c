#include "stdio.h"
#define MAXN 1e18

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

long long gcd(long long a, long long b)
{
    if (b > a)
        return gcd(b, a);
    if (b == 0) 
        return (a);
    return gcd(b, mnorm(a, b));
}

long long fastpow(long long a, long long n, long long mod)
{
    long long tmp;

    if (n == 0)
        return (1);
    if (n % 2 == 1) 
        return ((a * fastpow(a, n - 1, mod)) % mod);
    tmp = fastpow(a, n / 2, mod);
    return ((tmp * tmp) % mod);
}

int main(void)
{
    long long a;
    long long b;
    long long ret;
    
    scanf("%lld %lld", &a, &b);
    ret = fastpow(a, a, b);
    printf("%lld", ret);
    return (0);
}
