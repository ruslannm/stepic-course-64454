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
        return (1);
    dp = (long long **)malloc(sizeof(long long*) * (n + 1)); 
    i = -1;
    while (++i <= n)
    {
        dp[i] = (long long*)malloc(sizeof(long long) * (m + 1));
        j = -1;
        while (++j <= m)
            dp[i][j] = 0;
    };
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
    dp[0][0] = 1;
    i = 0;
    while (++i <= n)
    {
        j = 0;
        while (++j <= m)
        {
            if (a[i][j] == 0)
            {
               dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;//madd(dp[i][j - 1], dp[i - 1][j - 1], MOD);
               dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
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

   // scanf("%d %d", &n, &m);
    n = 1;
    m = 1;
    a = (int**)malloc(sizeof(int*) * (n + 2)); 
    i = -1;
    while (++i <= n)
        a[i] = (int*)malloc(sizeof(int) * (m + 2));
    i = 0;
    while (++i <= n)
    {
        j = 0;
        while (++j <= m)
        {
         //   scanf("%d", &a[i][j]);
            a[i][j] = 0;
        }
    }
//    a[1][2] = 1;
  //  a[5][3] = 1;
    printf("%lld\n", turtle(n, m, a));
    printf("ll=%lu\n", sizeof(long long));
    i = -1;
    while (++i <= n)
        free(a[i]);
    free(a);    
    return (0);
}