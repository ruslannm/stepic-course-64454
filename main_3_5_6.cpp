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
   s = 5; n = 5;
	vector <int> w(n + 1);
	vector <int> c(n + 1);
	vector <vector <int> > parent_x(n + 3, vector <int> (s + 3, -1));
	vector <vector <int> > parent_y(n + 3, vector <int> (s + 3, -1));

/*	i = 0;
	while (++i <= n)
		cin >> w[i];
	i = 0;
	while (++i <= n)
		cin >> c[i];
*/

	w[1] = 2;
	w[2] = 2;
	w[3] = 2;
	w[4] = 2;
	w[5] = 2;
	c[1] = 2;
	c[2] = 2;
	c[3] = 2;
	c[4] = 2;
	c[5] = 2;
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
				{
					parent_x[i][j] = i - 1; 
					parent_y[i][j] = j - w[i]; 
					dp[i][j] = dp[i - 1][j - w[i]] + c[i];
				}
				else 
				{
					parent_x[i][j] = i - 1; 
					parent_y[i][j] = j; 
					dp[i][j] = dp[i - 1][j];
				}
			}
			else
				{
					parent_x[i][j] = i - 1; 
					parent_y[i][j] = j; 
					dp[i][j] = dp[i - 1][j];
				}
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
	int ans_j = 0;
	while (++j <= s)
	{
		if (dp[n][j] > ret)
		{
			ret = dp[n][j];
			ans_j = j;
		}
	}
	cout << ret << " ";
	vector <int> ans;
	i = n;
	j = ans_j;
    while (i > 0 && j > 0)
	{
		while (dp[i][j] == dp[i - 1][j] && dp[i][j] != dp[i - 1][j - w[i]] + c[i])
			i--;
	    ans.push_back(i);
		cout << " i=" << i << endl;
		if (dp[i][j] == dp[i - 1][j - w[i]] + c[i])
			j -= w[i--];
		else if (dp[i][j] == dp[i - 1][j])
			i--;
    }
	i = ans.size();
	cout << i << endl;
	while (--i >= 0)
		cout << ans[i] << " ";
	return 0;
}
