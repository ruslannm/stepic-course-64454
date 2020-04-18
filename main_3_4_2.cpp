#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long f_max(long long a, long long b, long long c)
{
    if (a > b)
        return (a > c ? a : c);
    else 
        return (b > c ? b : c);
}

int main()
{
    int n;
    int i;
    
    cin >> n;
	vector <long long>  a(n + 1);
    vector <long long>  dp(n + 1);
    i = 0;
    dp[0] = 0;
    while (++i <= n)
    {
        cin >> a[i];
        if (i > 4)
            dp[i]= f_max(dp[i - 5], dp[i - 3], dp[i - 1]) + a[i];
        else if (i > 2)
            dp[i]= f_max(dp[i - 3], dp[i - 3], dp[i - 1]) + a[i];
        else 
            dp[i]= dp[i - 1] + a[i];
    }
    vector <long long> ans;
    i = n;
    while (i > 0)
    {
        ans.push_back(i);
        if (i > 4)
        {
            if (dp[i - 1] + a[i] == dp[i])
                i--;
            else if (dp[i - 3] + a[i] == dp[i])
                i = i - 3;
            else 
                i = i - 5;
        }
        else if (i > 2)
        {
            if (dp[i - 1] + a[i] == dp[i])
                i--;
            else 
                i = i - 3;
        }
        else 
            i--;
    }
    i = ans.size();
    cout << dp[n] << " " << i << endl;
    while (--i >= 0)
        cout << ans[i] << " ";
    return 0;
}
