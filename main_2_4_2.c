#include "stdio.h"
#define MOD 1000000007

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
    long long c;
    long long d;
    long long ret[2];
    
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    ret[0] = madd(a, d, MOD);
    ret[1] = madd(b, c, MOD);
    ret[0] = msum(ret[0], ret[1], MOD);
    
    ret[1] = fastpow(b, MOD - 2, MOD);
    ret[0] = madd(ret[0], ret[1], MOD);
    ret[1] = fastpow(d, MOD - 2, MOD);
    ret[0] = madd(ret[0], ret[1], MOD);
    printf("%lld", ret[0]);
    return (0);
}
