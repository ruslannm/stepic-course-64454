#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 1000001

using namespace std;

int main()
{
    int n;
    int m;
    int i;
    int j;
    
    cin >> n >> m;

    vector <vector <int> > a(n + 1, vector <int> (m + 1));
	vector <vector <int> > dp(n + 1, vector <int> (m + 1, MAXN));
    i = 0;
    //j = -1;
    //while (++j < m)
    //    a[i][j] = MAXN;
    dp[0][0] = 0;
    while (++i <= n)
    {
        j = 0;
    //    a[i][j] = MAXN;
        while (++j <= m)
        {
            cin >> a[i][j];
            dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]) + a[i][j];
        }
    }
    i = -1;
    while (++i <= n)
    {
        j = -1;
        while (++j <= m)
            cout << dp[i][j] << ' ';
        cout << "\n";
    }
    vector <pair <int, int> > ans;
    i = n;
    j = m;
    while (i > 0 && j > 0)
    {
        ans.push_back(make_pair(i, j));
        if (dp[i - 1][j] + a[i][j] == dp[i][j])
            i--;
        else if (dp[i][j - 1] + a[i][j] == dp[i][j])
            j--;
        else
        {
            i--;
            j--;
        }
    }
    i = ans.size();
    cout << dp[n][m] << " " << i << endl;
    while (--i >= 0)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
