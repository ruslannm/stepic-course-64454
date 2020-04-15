#include "stdio.h"

long long mnorm(long long d, long long mod)
{
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
        return ((a * fastpow(a, n - 1, mod)) % mod);
    tmp = fastpow(a, n / 2, mod);
    return ((tmp * tmp) % mod);
}

long long fastpow2(long long a, long long n)
{
    long long ret;

    ret = 1;
    while (n > 0)
    {
        if (n % 2 == 1) 
            ret *= n;
        ret = ret * ret;
        n /= 2;
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
//    return gcdext(r2, mnorm(r1, r2), x1, y1, x2, y2);
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

int main(void)
{
    long long a;
    long long n;
    long long m;
    long long tmp;
    long long tmp_mul_prev;
    long long tmp_mul_cur;
    long long tmp_mul;
    long long i;
    long long ret;
    
    scanf("%lld %lld %lld", &a, &n, &m);
    i = 1;
    tmp_mul = mdiv2(1, a, m); 
    tmp_mul_prev = tmp_mul;
    ret =  tmp_mul; 
    if (ret == -1)
    {
        printf("%d", -1);
        return (0);
    }
    while (++i <= n)
    {
        tmp_mul_cur = mdiv2(i, a, m); 
        tmp = mmul(tmp_mul_prev, tmp_mul_cur, m);
        tmp_mul_prev =  mmul(tmp_mul_prev, tmp_mul, m); 
        if (tmp == -1)
        {
            printf("%d", -1);
            return (0);
        }
        ret = madd(ret, tmp, m);
    }
    printf("%lld", ret);
    return (0);
}
