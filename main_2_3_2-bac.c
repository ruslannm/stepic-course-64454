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

int gcdext(int r1, int r2, int *x1, int *y1, int *x2, int *y2)
{
    int x;
    int y;

    if (r2 == 0) 
        return (1);
    x = *x1 - (r1 / r2) * *x2;
    y = *x1 - (r1 / r2) * *y2;
    *x1 = *x2;
    *x2 = x;
    *y1 = *y2;
    *y2 = y;
    return gcdext(r2, mnorm(r1, r2), x1, y1, x2, y2);
}

int main(void)
{
    int a;
    int b;
    int c;
    int x1;
    int y1;
    int x2;
    int y2;
    
    scanf("%d %d %d", &a, &b, &c);
    x1 = 1;
    y1 = 0;
    x2 = 0;
    y1 = 1;
    gcdext(a, b, x1, y1, x2, y2);
    printf("%d\n", c);
    return (0);
}
