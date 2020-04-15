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

int main(void)
{
    long long a;
    long long b;
    long long nod;    
    long long tmp;
    
    scanf("%lld %lld", &a, &b);
    nod = gcd(a, b);
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    tmp = a / nod;
    if (tmp < MAXN / b)
        printf("%lld", b * tmp);
    else
        printf("%d", -1);
 
    return (0);
}
