#include "stdio.h"
#include "stdlib.h"
#define MOD     1000000007
#define MAXN    1505


long long mnorm(long long d, long long mod)
{
    return ((d % mod + mod) % mod);
}

long long madd(long long x, long long y, long long mod)
{
    return (mnorm((mnorm(x, mod) + mnorm(y, mod)) % mod, mod));
}

int diag(int i, int j, int n)
{
    int ret;

    ret = n + j - i - 1;
    return (ret);
}

long long  queen(int n, int m)
{
    int i;
    int j;
    long long **dp;
    long long pref_col[MAXN];
    long long pref_row[MAXN];
    long long pref_diag[2 * MAXN];
    long long ret;

    if (1 == n && 1 == m)
        return (1);
    
    dp = (long long **)malloc(sizeof(long long*) * (n + 1)); 
    i = -1;
    while (++i <= n)
    {
        j = -1;
        dp[i] = (long long*)malloc(sizeof(long long) * (m + 1));
        while (++j <= m)
        {
            dp[i][j] = 0;
            pref_col[j] = 0;
            pref_row[j] = 0;
            pref_diag[i + j] = 0;
        }
    }
    i = 0;
    while (++i <= n)
    {
        j = 0;
        while (++j <=m)
        {
            if (1 == i && 1 == j)
            {
                pref_col[j] = 1;
                pref_row[j] = 1;
                pref_diag[diag(i, j, n)] = 1;
            }
            else
            {
                pref_row[j] = (pref_row[j - 1] + dp[i][j]) % MOD;
                dp[i][j] = (pref_row[j - 1] + pref_col[j] + pref_diag[diag(i, j, n)]) % MOD;
                pref_row[j] = (pref_row[j - 1] + dp[i][j]) % MOD;
                pref_col[j] = (pref_col[j] + dp[i][j]) % MOD;
                pref_diag[diag(i, j, n)] = (pref_diag[diag(i, j, n)] + dp[i][j]) % MOD;
            }
        }
    }
    ret = dp[n][m];
    i = -1;
    while (++i <= n)
        free(dp[i]);
    free(dp);  
    return (ret);
}

int main(void)
{
    int n;
    int m;

    scanf("%d %d", &n, &m);
    printf("%lld\n", queen(n, m));
    return (0);
}