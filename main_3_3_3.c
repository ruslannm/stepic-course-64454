#include "stdio.h"
#include "stdlib.h"

long long f_max(long long  a, long long b)
{
    return (a > b ? a: b);
}

long long  ski(int n, int **a)
{
    int i;
    int j;
    int **dp;
    long long ret;

    if (n == 1)
        return (a[0][0]);
    dp = (int**)malloc(sizeof(int*) * (n + 1)); 
    i = -1;
    while (++i < n)
        dp[i] = (int*)malloc(sizeof(int) * (n + 1));
    dp[0][0] = a[0][0];
    i = 0;
    j = 0;
    while (++j < n)
        dp[i][j] = dp[i][j - 1] + a[i][j];
    ret = dp[i][j - 1];
    j = 0;
    while (++i < n)
        dp[i][j] = dp[i - 1][j] + a[i][j];
    if (dp[i - 1][j] > ret)
        ret = dp[i - 1][j];
    i = 0;
    j = 0;
    while (++i < n - 1)
    {
        j = 0;
        while (++j < n - i)
            dp[i][j] = a[i][j] + f_max(dp[i][j - 1], dp[i - 1][j]);
        if (dp[i][j - 1] > ret)
            ret = dp[i][j - 1];
    }
    i = -1;
    while (++i < n)
        free(dp[i]);
    free(dp);  
    return (ret);
}

int main(void)
{
    int n;
    int **a;
    int i;
    int k;

    scanf("%d", &n);
    a = (int**)malloc(sizeof(int*) * (n + 1)); 
    i = -1;
    while (++i < n)
        a[i] = (int*)malloc(sizeof(int) * (n + 1));
    k = -1;
    while (++k < n)
    {
        i = k + 1;
        while (--i >= 0)
            scanf("%d", &a[i][k - i]);
    }  
    printf("%lld\n", ski(n, a));
    i = -1;
    while (++i < n)
        free(a[i]);
    free(a);    
    return (0);
}