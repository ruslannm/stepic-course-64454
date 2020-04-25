#include <iostream>
#include <vector>
#define MAXDP 1000000000

using namespace std;

int main()
{
	int n;
	int s;
	int i;
	int j;
	int ret;

//	cin >> s >> n;
   s = 8; n = 4;
	vector <int> w(n + 1);
	vector <int> c(n + 1);
/*	i = 0;
	while (++i <= n)
		cin >> w[i];
	i = 0;
	while (++i <= n)
		cin >> c[i];
*/
	w[1] = 2;
	w[2] = 4;
	w[3] = 4;
	w[4] = 7;
	c[1] = 2;
	c[2] = 5;
	c[3] = 5;
	c[4] = 9;

	vector <vector <int> > dp(n + 1, vector <int> (s + 1, -MAXDP));
	dp[0][0] = 0;
	i = 0;
	while (++i <= n)
	{
		j = -1;
		while (++j <= s)
		{
			if (w[i] <= j)
			{
				if (dp[i - 1][j - w[i]] + c[i] > dp[i - 1][j])
					dp[i][j] = dp[i - 1][j - w[i]] + c[i];
				else
					dp[i][j] = dp[i - 1][j];
			}
			else
				dp[i][j] = dp[i - 1][j];

		}
	}
	cout << "dp\n";
	i = -1;
	while (++i <= n)
	{
		j = -1;
		while (++j <= s)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	j = -1;
	ret = 0;
	while (++j <= s)
	{
		if (dp[n][j] > ret)
			ret = dp[n][j];
	}
	cout << ret << " ";
	vector <int> ans;
	i = n;
	j = s;
    while (i > 0 && j > 0)
	{
		while (dp[i][j] == dp[i - 1][j] && dp[i - 1][j - w[i]] + c[i] < dp[i - 1][j])
			i--;
	    ans.push_back(i);
		if (dp[i][j] == dp[i - 1][j])
			i--;
		else
			j -= w[i--];
    }
	i = ans.size();
	cout << i << endl;
	while (--i >= 0)
		cout << ans[i] << " ";
	return 0;
}
