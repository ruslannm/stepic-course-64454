#include "stdio.h"
#include "stdlib.h"
#define MOD     1000000009

long long mnorm(long long d, long long mod)
{
    return ((d % mod + mod) % mod);
}

long long madd(long long x, long long y, long long mod)
{
    return (mnorm((mnorm(x, mod) + mnorm(y, mod)) % mod, mod));
}

long long  turtle(int n, int m, int **a)
{
    int i;
    int j;
    long long **dp;
    long long ret;

    if (n == 1 && m == 1)
        return (a[0][0]);
    dp = (long long **)malloc(sizeof(long long*) * (n + 2)); 
    i = -1;
    while (++i <= n)
    {
        dp[i] = (long long*)malloc(sizeof(long long) * (m + 2));
        j = -1;
        while (++j <= m)
            dp[i][j] = 0;
    };
    dp[0][0] = 1;
    i = 0;
    while (++i <= n)
    {
        j = 0;
        while (++j <= m)
        {
            if (a[i][j] == 0)
            {
               dp[i][j] = madd(dp[i][j - 1], dp[i - 1][j - 1], MOD);
               dp[i][j] = madd(dp[i][j], dp[i - 1][j], MOD);
            }
        }
    }
    ret = dp[n][m];
    
    printf("\n");
    i = -1;
    while (++i <= n)
    {
        j = -1;
        while (++j <= m)
        {
         //   printf("dp=%lld, i=%d j=%d ", dp[i][j], i, j);;
   printf("%lld ", dp[i][j]);
        }
        printf("\n");;
    }
    
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
    int **a;
    int i;
    int j;

    scanf("%d %d", &n, &m);
    a = (int**)malloc(sizeof(int*) * (n + 2)); 
    i = -1;
    while (++i <= n)
        a[i] = (int*)malloc(sizeof(int) * (m + 2));
    i = 0;
    while (++i <= n)
    {
        j = 0;
        while (++j <= m)
            scanf("%d", &a[i][j]);
    }
    printf("%lld\n", turtle(n, m, a));
    i = -1;
    while (++i <= n)
        free(a[i]);
    free(a);    
    return (0);
}