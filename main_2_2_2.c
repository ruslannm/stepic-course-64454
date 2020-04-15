#include "stdio.h"
#define	REM	1000007

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

long long rem(long long a, long long b)
{
	long add1;
    long add2;

    add1 = madd(a, a, REM);
    add2 = madd(b, b, REM);
	return (msub(add1, add2, REM));
}

int main(void)
{
    long a;
    long b;
    
    scanf("%ld %ld", &a, &b);
    printf("%lld\n", rem(a, b));
    return (0);
}
