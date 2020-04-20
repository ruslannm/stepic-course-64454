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
//	while (++i <= n)
//		cin >> w[i];
	w[1] = 2;
	w[2] = 3;
	w[3] = 4;
	w[4] = 4;
	w[5] = 6;
	w[6] = 9;
	vector <vector <int> > dp(n + 1, vector <int> (s + 1, 0));
	vector <vector <int> > parent_x(n + 1, vector <int> (s + 1, -1));
	vector <vector <int> > parent_y(n + 1, vector <int> (s + 1, -1));

	dp[0][0] = 0;
	parent_x[0][0] = 0;
	parent_y[0][0] = 0;
	i = 0;
	while (++i <= n)
	{
		j = -1;
		while (++j <= s)
		{
			if (dp[i - 1][j] < dp[i - 1][j - w[i]])
			{
				dp[i][j] = dp[i - 1][j - w[i]] + w[i];
				parent_x[i][j] = i - 1;
				parent_y[i][j] = j - w[i];
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
		if (dp[n][ret] <= s) {
			i = n;
			j = ret;
			cout << ret << " ";
			break;
		}
	}
	vector <pair <int, int> > ans;
	int old_i;
	int old_j;
	while (i > 0 && j > 0)
	{
		ans.push_back(make_pair(i, j));
		old_i = i;
		old_j = j;
		i = parent_x[old_i][old_j];
		j = parent_y[old_i][old_j];
	}
	i = ans.size();
	cout << i << endl;
	while (--i >= 0)
		cout << ans[i].first << " ";
	return 0;
}
