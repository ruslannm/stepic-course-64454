#include "stdio.h"
#include "stdlib.h"
#define MAXN    101

long long f_height(long long h, long long  dp1, long long  dp2)
{
    long long ha1;
    long long ha2;

    ha1 = dp1 + h; 
    ha2 = dp2 + h; 
    return (ha1 > ha2 ? ha1: ha2);
}

long long  ski(int n, int **a)
{
    int i;
    int j;
    int **dp;
    long long ret;

    printf("\n");
    i = -1;
    while (++i < n)
    {
        j = -1;
        while (++j < n - i)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    ret = 0;
    dp = (int**)malloc(sizeof(int*) * (n + 1)); 
    i = -1;
    while (++i < n)
        dp[i] = (int*)malloc(sizeof(int) * (n + 1));
    dp[0][0] = a[0][0];
    i = 0;
    j = 0;
    while (++j < n)
    {
        dp[i][j] = dp[i][j - 1] + a[i][j];
        if ((j == n - 1) && dp[i][j] > ret)
        {
            ret = dp[i][j];
            printf("dp=%d i=%d j=%d\n", dp[i][j], i, j);
        }
    }
    j = 0;
    while (++i < n)
    {
        dp[i][j] = dp[i - 1][j] + a[i][j];
        if ((i == n - 1) && dp[i][j] > ret)
        {
            ret = dp[i][j];
            printf("dp=%d i=%d j=%d\n", dp[i][j], i, j);
        }
    }
    i = 0;
    j = 0;
    while (++i < n)
    {
        j = 0;
        while (++j <= i)
        {
            dp[i][j] = f_height(a[i][j], dp[i][j - 1], dp[i - 1][j]);
            if ((i + j == n - 1) && dp[i][j] > ret)
                ret = dp[i][j];
        }
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
    int m;
    int **a;
    int i;
    int j;
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