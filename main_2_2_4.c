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

int solve(int x, int n, int m, int *ar)
{
    int i;
    int ret;
    long power;
    long member;

    ret = mnorm(ar[0], m);
    i = 0;
    while (++i <= n)
    {
        if (i == 1)
            power = mnorm(x, m);
        else
            power = madd(power, x, m);
        member = madd(power, ar[i], m);
        ret = msum(ret, member, m);
    }
	return (ret);
}

int main(void)
{
    int n;
    int m;
    int i;
    int ar[1001];
    int ret;
    
    scanf("%d %d", &n, &m);
    i = n;
    while (i >= 0)
        scanf("%d", &ar[i--]);
    i = -1;
    while (++i <= m)
    {
        ret = solve(i, n, m, ar);
        if (ret == 0)
        {
            printf("%d\n", i);
            return (0);
        }
    }
    printf("%d\n", -1);
    return (0);
}
