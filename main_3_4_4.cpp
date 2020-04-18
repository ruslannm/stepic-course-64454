#include <iostream>
#include <vector>
#include <algorithm>
#define MAXD    1e18L

using namespace std;

int main()
{
	int n;
	int m;
	int i;
	int j;
	int d;

	cin >> n >> m;
	vector <vector <long long> > ar(n + 3, vector <long long> (m + 3, 0));
	vector <vector <long long> > dp(n + 3, vector <long long> (m + 3, MAXD));
	vector <vector <int> > parent_x(n + 3, vector <int> (m + 3, -1));
	vector <vector <int> > parent_y(n + 3, vector <int> (m + 3, -1));
	i = 1;
	while (++i <= n + 1)
	{
		j = 1;
		while (++j <= m + 1)
		{
			cin >> ar[i][j];
		}
	}
	dp[2][2] = ar[2][2];
	d = 1;
	while (++d < n + m)
	{
		i = 2 + (d > m ? d - m : 0);
		while (i < n + 2 && i < d + 2)
		{
			j = d + 1 + 2 - i;
			dp[i][j] = min(min(dp[i - 2][j + 1], dp[i - 2][j - 1]), min(dp[i - 1][j - 2], dp[i + 1][j - 2]));
			if (dp[i][j] != MAXD)
			{
				if (dp[i][j] == dp[i - 2][j + 1]) {
					parent_x[i][j] = i - 2; 
					parent_y[i][j] = j + 1; 
				}
				else if (dp[i][j] == dp[i - 2][j - 1]) {
					parent_x[i][j] = i - 2; 
					parent_y[i][j] = j - 1; 
				}
				else if (dp[i][j] == dp[i - 1][j - 2]) {
					parent_x[i][j] = i - 1; 
					parent_y[i][j] = j - 2; 
				}
				else if (dp[i][j] == dp[i + 1][j - 2]) {
					parent_x[i][j] = i + 1; 
					parent_y[i][j] = j - 2; 
				}
				dp[i][j] += ar[i][j];
			}
			++i;
		}
	}
	if (dp[n + 1][m + 1] == MAXD)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	vector <pair <int, int> > ans;
	i = n + 1;
	j = m + 1;
	int old_i;
	int old_j;

	while (i > 0 && j > 0)
	{
		ans.push_back(make_pair(i - 1, j - 1));
		old_i = i;
		old_j = j;
		i = parent_x[old_i][old_j];
		j = parent_y[old_i][old_j];
	}
	i = ans.size();
	cout << dp[n + 1][m + 1] << " " << i << endl;
	while (--i >= 0)
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}
