#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int i;
    int a;
    
    cin >> n;
    vector <int>  dp(n + 1);
    i = 1;
    dp[1] = 0;
    while (++i <= n)
    {
        dp[i] = dp[i - 1];
        if (i % 3 == 0 && dp[i / 3] < dp[i])
            dp[i] = dp[i / 3];
        if (i % 2 == 0 && dp[i / 2] < dp[i])
            dp[i]= dp[i / 2];
        dp[i]++;
    }
    vector <long long> ans;
    i = n;
    while (i > 0)
    {
        ans.push_back(i);
        if (dp[i - 1] + 1 == dp[i])
            i--;
        else if (i % 2 == 0 && dp[i / 2] + 1 == dp[i])
            i = i / 2;
        else 
            i = i / 3;
    }
    i = ans.size();
    cout << dp[n] << endl;
    while (--i >= 0)
        cout << ans[i] << " ";
    return 0;
}
