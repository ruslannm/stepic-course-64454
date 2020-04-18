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

	//cin >> n >> m;
	n = 1000;
	m = 1000;
	vector <vector <long long> > ar(n + 1, vector <long long> (m + 1, 0));
	vector <vector <long long> > dp(n + 1, vector <long long> (m + 1, MAXD));
	vector <int> pref_col(m + 1, 0);
	vector <int> pref_row(m + 1, 0);

	vector <vector <int> > parent_x(n + 1, vector <int> (m + 1, -1));
	vector <vector <int> > parent_y(n + 1, vector <int> (m + 1, -1));
	i = 0;
	while (++i <= n)
	{
		j = 0;
		while (++j <= m)
			ar[i][j] = 1000 * 1000 * 1000;//	cin >> ar[i][j];
	}
   i = 0;
    while (++i <= n)
    {
        j = 0;
        while (++j <=m)
        {
            if (1 == i && 1 == j)
            {
				dp[1][1] = ar[1][1];
                pref_col[j] = 1;
                pref_row[j] = 1;
            }
            else
            {
				dp[i][j] = min(dp[i][pref_row[j - 1]], dp[pref_col[j]][j]);
				if (dp[i][j] == dp[i][pref_row[j - 1]])
				{
					parent_x[i][j] = i; 
					parent_y[i][j] = pref_row[j - 1];
				}
				else
				{
					parent_x[i][j] = pref_col[j]; 
					parent_y[i][j] = j;
				}
				dp[i][j] += ar[i][j];
				if (ar[i][j] < 0)
				{
					pref_col[j] = i;
					pref_row[j] = j;
				}
				else
				{
					if (i == 1)
						pref_col[j] = 1;
					if (j == 1)
						pref_row[j] = 1;
					else 
					{
						if (dp[i][j] < dp[i][j - 1])
							pref_row[j] = j;
						else 
							pref_row[j] = pref_row[j - 1];
					}
				}
            }
        }
    }
	vector <pair <int, int> > ans;
	i = n;
	j = m;
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
	cout << dp[n][m] << " " << i << endl;
	while (--i >= 0)
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}
