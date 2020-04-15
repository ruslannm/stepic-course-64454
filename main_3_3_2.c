#include "stdio.h"
#include "stdlib.h"
#define MAXN    101

long long f_abs(long long  a, long long b)
{
    long long tmp;

    tmp = a - b;
    return (tmp < 0 ? -tmp : tmp);
}

long long f_height(long long h, long long  a1, long long  dp1, long long a2, long long  dp2)
{
    long long ha1;
    long long ha2;

    ha1 = dp1 + f_abs(h, a1); 
    ha2 = dp2 + f_abs(h, a2); 
    return (ha1 < ha2 ? ha1: ha2);
}

long long  turtle(int n, int m, int **a)
{
    int i;
    int j;
    long long  dp[MAXN][MAXN];

    dp[0][0] = 0;
    i = 0;
    j = 0;
    while (++j < m)
        dp[i][j] = dp[i][j - 1] + f_abs(a[i][j], a[i][j - 1]);
    j = 0;
    while (++i < n)
        dp[i][j] = dp[i - 1][j] + f_abs(a[i][j], a[i - 1][j]);
    i = 0;
    while (++i < n)
    {
        j = 0;
        while (++j < m)
            dp[i][j] = f_height(a[i][j], a[i][j - 1], dp[i][j - 1], a[i - 1][j], dp[i - 1][j]);
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

    scanf("%d %d", &m, &n);
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