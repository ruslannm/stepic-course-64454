#include "stdio.h"
#include "stdlib.h"
#define MOD     1000000123

long long mnorm(long long d, long long mod)
{
    return ((d % mod + mod) % mod);
}

long long madd(long long x, long long y, long long mod)
{
    return (mnorm((mnorm(x, mod) + mnorm(y, mod)) % mod, mod));
}

long long  horse(int n, int m)
{
    int i;
    int j;
    int d;
    long long **dp;
    long long ret;

    dp = (long long **)malloc(sizeof(long long*) * (n + 3)); 
    i = -1;
    while (++i <= n + 2)
    {
        dp[i] = (long long*)malloc(sizeof(long long) * (m + 3));
        j = -1;
        while (++j <= m + 2)
            dp[i][j] = 0;
    };
    dp[2][2] = 1;
    d = 1;
    while (++d < n + m)
    {
        i = 2 + (d > m ? d - m : 0);
        while (i < n + 2 && i < d + 2)
        {
            j = d + 1 + 2 - i;
            dp[i][j] = (dp[i - 2][j + 1] + dp[i - 2][j - 1] + dp[i - 1][j - 2] + dp[i + 1][j - 2]) % MOD;
            ++i;
        }
    }
    ret = dp[n + 1][m + 1];
    i = -1;
    while (++i <= n + 2)
        free(dp[i]);
    free(dp);  
    return (ret);
}

int main(void)
{
    int n;
    int m;

    scanf("%d %d", &n, &m);
    printf("%lld\n", horse(n, m));
    return (0);
}