int main(void)
{
    int dp[7][6];
    int a;
    int b;
    

    b = 5;
    while(b >= 0)
    {
        a = 0;
        while (a < 6)
        {
            dp[a][b] = -100;
            a++;
        }
        b--;
    }
    a = 0;
    while (a < 7)
    {
        dp[a][5] = 1;
        a++;
    }
    b = 0;
    while (b < 6)
    {
        dp[0][b] = 2;
        b++;
    }
    b = 4;
    while(b >= 0)
    {
        a = 5;
        while (a > 0)
        {
            dp[a][b] = dp[a - 1][b + 1] + dp[a + 1][b + 1];
            a--;
        }
        b--;
    }
    return (0);
}