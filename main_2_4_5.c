#include "stdio.h"
#define MAXN    1000000
#define MOD     1000000007

long long mnorm(long long d, long long mod)
{
     printf("**\n");
    return ((d % mod + mod) % mod);
}

long long madd(long long x, long long y, long long mod)
{
    return (mnorm((mnorm(x, mod) + mnorm(y, mod)) % mod, mod));
}

long long msub(long long x, long long y, long long mod)
{
    return (mnorm((mnorm(x, mod) - mnorm(y, mod)) % mod, mod));
}

long long mmul(long long x, long long y, long long mod)
{
    return (mnorm((mnorm(x, mod) * mnorm(y, mod)) % mod, mod));
}

long long fastpow(long long a, long long n, long long mod)
{
    long long tmp;

    if (n == 0)
        return (1);
    if (n % 2 == 1) 
    {
        printf("*");
        return ((a * fastpow(a, n - 1, mod)) % mod);
    }
    tmp = fastpow(a, n / 2, mod);
    printf("*");
    return ((tmp * tmp) % mod);
}

long long fastpow2(long long a, long long n)
{
    long long ret;
    int i;
    int j;

    ret = 1;
    i = 0;
    j = 0;
    while (n > 0)
    {
        if (n % 2 == 1) 
        {
            n = n - 1;
            printf("*%d*j=*%d*\n", ++i, ++j);
            ret *= a;
        }
        a *= a;
        n /= 2;
        printf("*%d*\n", ++i);
    }
    return (ret);
}


long long mdiv(long long a, long long b, long long pmod)
{
    return (mmul(a, fastpow(b, pmod - 2, pmod), pmod));
}

int gcd(int a, int b)
{
    if (b == 0) 
        return (a);
    return gcd(b, mnorm(a, b));
}

long long gcdext(long long r1, long long r2, long long *x1, long long *y1, long long *x2, long long *y2)
{
    long long x;
    long long y;

    if (r2 == 0) 
        return (1);
    x = *x1 - (r1 / r2) * *x2;
    y = *y1 - (r1 / r2) * *y2;
    *x1 = *x2;
    *x2 = x;
    *y1 = *y2;
    *y2 = y;
    return gcdext(r2, mnorm(r1, r2), x1, y1, x2, y2);
}

long long mdiv2(long long a, long long b, long long mod)
{
    long long x1;
    long long y1;
    long long x2;
    long long y2;
    long long d;
    long long nod;

    nod = gcd(mod, b);
    if (a % nod)
        return (-1);
    x1 = 1;
    y1 = 0;
    x2 = 0;
    y2 = 1;
    d = gcdext(b, mod, &x1, &y1, &x2, &y2);
    if (a % d != 0)
        return (-1);
    return (mmul(a / d, x1, mod));
}

long long mfact(long long n, long long mod, long long *ar)
{
    long long i;
    long long ret;

    i = 0;
    ret = 1;
    ar[i] = ret;
    while (++i <=n)
    {
        ret = mmul(ret, i, mod);
        ar[i] = ret;
    }
    return (ret);
}

int main(void)
{
    long long a;
    long long b;
    long long d;
    long long a1;
    long long b1;
    
    printf("%lld ", fastpow2(2, 2020));
    printf("%lld ", fastpow(2, 2020, 3));
    /*while (1)
    {
***********
*********************************
***********************************
**************************************
****************************
*****************
        scanf("%lld %lld", &a, &b);
        if (a == 0 && b == 0)
            break ;
        a1 = a;
        b1 = b;
        d = gcd(a1, b1);
        printf("%lld ", d);
        a1 = a - b;
        b1 = b;
        d = gcd(a1, b1);
        printf("%lld ", d);
        a1 = a + b;
        b1 = b;
        d = gcd(a1, b1);
        printf("%lld ", d);
        a1 = mnorm(a, b);
        b1 = b;
        d = gcd(a1, b1);
        printf("%lld ", d);
        a1 = a + b;
        b1 = a - b;
        d = gcd(a1, b1);
        printf("%lld ", d);
        a1 = mnorm(a, b);
        b1 = a;
        d = gcd(a1, b1);
        printf("%lld\n", d);
    }
    */
    return (0);
}
