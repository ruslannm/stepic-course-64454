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
	int ret = 30000000;

	cin >> s >> n;
//   s = 2; n = 3;
	vector <int> w(n + 1);
	vector <int> c(n + 1);
	i = 0;
	while (++i <= n)
		cin >> w[i];
	i = 0;
	while (++i <= n)
		cin >> c[i];
/*
	w[1] = 3;
	w[2] = 3;
	w[3] = 3;
	w[4] = 1;
	w[5] = 10;

	c[1] = 0;
	c[2] = 0;
	c[3] = 0;
	c[4] = 3;
	c[5] = 3;
*/
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
	cout << "dp-end\n";
	j = -1;
	ret = 0;
	int ans_j = 0;
	while (++j <= s)
	{
		if (dp[n][j] >= ret)
		{
			ret = dp[n][j];
			ans_j = j;
		}
	}
	cout << ret << " ";
	vector <int> ans;
	i = n;
	j = ans_j;
    while (i > 0 && j >= 0)
	{
		if (w[i] <= j && dp[i][j] == dp[i - 1][j - w[i]] + c[i])
		{
			ans.push_back(i);
			j -= w[i];
		}
		i--;
    }
	i = ans.size();
	cout << i << endl;
	while (--i >= 0)
		cout << ans[i] << " ";
	return 0;
}
