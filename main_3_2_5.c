#include "stdio.h"
#define MAXN    10 //500005
#define MOD     1000000007

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

long long calc(long long n, long long k, char *s)
{
    long i;
    long j;
    long long dp[MAXN];
    long long dps;

    dps = 0;
    i = -1;

    while (++i < k)
    {
        dp[i] = 0;
        if (i > 0)
            dps = madd(dps, dp[i - 1], MOD);
        if (s[i] == '0')
            dp[i] = madd(dps, 1, MOD);
    }
    i--;
    while (++i < n)
    {
        dp[i] = 0;        
        dps = madd(dps, dp[i - 1], MOD);
        if (i > k)
            dps = msub(dps, dp[i - 1 - k], MOD);
        if (s[i] == '0')
            dp[i] = dps;
        else
            dp[i] = 0;
    }
    return dp[i - 1];
}

int main(void)
{
    long long n;
    long long k;
    char s[MAXN];

    scanf("%lld %lld", &n, &k);
    scanf("%s", s);
   /* n = 8; k = 3;
    s[0] = '0';
    s[1] = '1';
    s[2] = '1';
    s[3] = '0';
    s[4] = '0';
    s[5] = '0';
    s[6] = '1';
    s[7] = '0';
*/
    printf("%lld\n", calc(n, k, s));
    return (0);
}