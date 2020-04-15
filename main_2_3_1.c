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

int gcd(int a, int b, int *c)
{
    if (b == 0) 
        return (a);
    *c = *c + 1;
    return gcd(b, mnorm(a, b), c);
}

int main(void)
{
    int a;
    int b;
    int c;
    
    scanf("%d %d", &a, &b);
    c = 0;
    gcd(a, b, &c);
    printf("%d\n", c);
    return (0);
}
