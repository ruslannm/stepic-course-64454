#include "stdio.h"
#define	REM	1000003

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

long long fact(long long n)
{
    long long i;
    long long ret;

    if (n >= REM)
        return (0);
    ret = 1;
    i = 0;
    while (++i <= n)
    {
        ret = madd(ret, i, REM);
    }
	return (ret);
}

int main(void)
{
    long long n;
    
    scanf("%lld", &n);
    printf("%lld\n", fact(n));
    return (0);
}
