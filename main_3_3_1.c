#include "stdio.h"
#include "stdlib.h"
#define MAXN    1001

long long f_min(long long a, long long  b, long long  c)
{
    if (a < b)
        return (a < c ? a : c);
    else 
        return (b < c ? b : c);
}

long long  turtle(int n, int m, int **a)
{
    int i;
    int j;
    long long  dp[MAXN][MAXN];

    dp[0][0] = a[0][0];
    i = 0;
    j = 0;
    while (++j < m)
        dp[i][j] = dp[i][j - 1] + a[i][j];
    j = 0;
    while (++i < n)
        dp[i][j] = dp[i - 1][j] + a[i][j];
    i = 0;
    while (++i < n)
    {
        j = 0;
        while (++j < m)
            dp[i][j] = f_min(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
    }
    if (j == 0)
        j = 1;
    return (dp[i - 1][j - 1]);
}

int main(void)
{
    int n;
    int m;
    int **a;
    int i;
    int j;

    scanf("%d %d", &n, &m);
    a = (int**)malloc(sizeof(int*) * (n + 1)); 
    i = -1;
    while (++i < n)
    {
        a[i] = (int*)malloc(sizeof(int) * (m + 1));
        j = -1;
        while (++j < m)
            scanf("%d", &a[i][j]);
    }
    printf("%lld\n", turtle(n, m, a));
    i = -1;
    while (++i < n)
        free(a[i]);
    free(a);    
    return (0);
}