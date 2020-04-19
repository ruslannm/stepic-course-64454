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
	vector <vector <long long> > ar(n + 1, vector <long long> (m + 1, 0));
	vector <vector <long long> > dp(n + 1, vector <long long> (m + 1, MAXD));
	vector <int> pref_i(m + 1, 0);  // i-coordinate best parent for current dp
	vector <int> pref_j(m + 1, 0);  // j-coordinate best parent for current dp
	vector <vector <int> > pref_d(n + 1, vector <int> (m + 1, 0)); // diagonale best parent for current dp
	
	vector <vector <int> > parent_i(n + 1, vector <int> (m + 1, 0));
	vector <vector <int> > parent_j(n + 1, vector <int> (m + 1, 0));
	i = 0;
	while (++i <= n)
	{
		j = 0;
		while (++j <= m)
			cin >> ar[i][j];
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
                pref_i[j] = 1;
                pref_j[j] = 1;
				pref_d[i][j] = 1;
            }
            else
            {
				dp[i][j] = min(min(dp[i][pref_j[j - 1]], dp[pref_i[j]][j]), dp[i - pref_d[i - 1][j - 1]][j - pref_d[i - 1][j - 1]]);
				if (dp[i][j] == dp[i][pref_j[j - 1]])
				{
					parent_i[i][j] = i; 
					parent_j[i][j] = pref_j[j - 1];
				}
				else if (dp[i][j] == dp[pref_i[j]][j])
				{
					parent_i[i][j] = pref_i[j]; 
					parent_j[i][j] = j;
				}
				else
				{
					parent_i[i][j] = i - pref_d[i - 1][j - 1]; 
					parent_j[i][j] = j - pref_d[i - 1][j - 1];
				}
				dp[i][j] += ar[i][j];
				if (i == 1)
					pref_i[j] = 1;
				if (j == 1)
					pref_j[j] = 1;
				else 
					pref_j[j] = pref_j[j - 1];
				if (dp[i][j] < dp[i][pref_j[j - 1]])
					pref_j[j] = j;
				if (dp[i][j] < dp[pref_i[j]][j])
					pref_i[j] = i;
				if (dp[i][j] < dp[i - pref_d[i - 1][j - 1]][j - pref_d[i - 1][j - 1]])
					pref_d[i][j] = 1;
				else
					pref_d[i][j] = pref_d[i - 1][j - 1] + 1;
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
		i = parent_i[old_i][old_j];
		j = parent_j[old_i][old_j];
	}
	i = ans.size();
	cout << dp[n][m] << " " << i << endl;
	while (--i >= 0)
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}
