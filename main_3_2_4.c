#include "stdio.h"
#define MAXN    500005
#define MOD     1000000007

long long mnorm(long long d, long long mod)
{
    return ((d % mod + mod) % mod);
}

long long madd(long long x, long long y, long long mod)
{
    return (mnorm((mnorm(x, mod) + mnorm(y, mod)) % mod, mod));
}

long long calc(long long n, char *s)
{
    long i;
    long long dp[MAXN];

    i = -1;
    while (++i < n)
    {
        if (s[i] == '0')
        {
            if (i == 0)
                dp[i] = 1;
            else if (i == 1)
                dp[i] = 1 + dp[i - 1];
            else if (i == 2)
                dp[i] = 1 + dp[i - 1] + dp[i - 2];
            else
            {
                dp[i] = madd(dp[i - 1], dp[i - 2], MOD);
                dp[i] = madd(dp[i], dp[i - 3], MOD);
            }
        }
        else
            dp[i] = 0;        
    }
    return dp[i - 1];
}



int main(void)
{
    long long n;
    int i;
    long long tmp;
    char s[MAXN];

    scanf("%lld", &n);
    scanf("%s", s);
    printf("%lld\n", calc(n, s));
    return (0);
}