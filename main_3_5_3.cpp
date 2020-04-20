#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int s;
	int i;
	int j;
	int a;
	int ret;

	//cin >> s >> n;
	s = 10; n = 6;
	vector <int> w(n + 1);

	i = 0;
	//while (++i <= n)
	//	cin >> w[i];
	w[1] = 2;
	w[2] = 3;
	w[3] = 4;
	w[4] = 4;
	w[5] = 6;
	w[6] = 9;
	vector <vector <int> > dp(n + 1, vector <int> (s + 1, 0));

	dp[0][0] = 1;
	i = 0;
	while (++i <= n)
	{
		j = -1;
		while (++j <= s)
		{
			if (w[i] <= j)
			{
				if (1 == dp[i - 1][j - w[i]])
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	ret = ++s;
	while (--ret >= 0)
	{
		if (dp[n][ret] == 1) {
			i = n;
			j = ret;
			cout << ret << " ";
			break;
		}
	}
	vector <pair <int, int> > ans;
	while (i > 0 && j > 0)
	{
		ans.push_back(make_pair(i, j));
		j = j - w[i];
		i = 0;
		while (dp[i][j] != 1)
			++i;
	}
	i = ans.size();
	cout << i << endl;
	while (--i >= 0)
		cout << ans[i].first << " ";
	return 0;
}
