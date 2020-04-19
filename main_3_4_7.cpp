#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int k;
	int i;
	int j;

	cin >> n >> k;
	vector <long long> ar(n + 1, 0);
	vector <long long> dp(n + 1, 0);
	vector <int> pref_i(n + 1, 0);  // i-coordinate best parent for current dp
	vector <int> parent_i(n + 1, 0);
	i = 0;
	while (++i <= n)
		cin >> ar[i];
    i = 0;
    while (++i <= n)
    {
		dp[i] = dp[i - 1];
		parent_i[i] = i - 1;
		j = 1;
		while (++j <= k && i - j >= 0)
		{
			if (dp[i - j] < dp[i])
			{
				dp[i] = dp[i - j];
				parent_i[i] = i - j;
			}
		}
		dp[i] += ar[i];
	}

	vector <int> ans;
	i = n;
	int old_i;
	while (i > 0)
	{
		ans.push_back(i);
		old_i = i;
		i = parent_i[old_i];
	}
	i = ans.size();
	cout << dp[n] << " " << i << endl;
	while (--i >= 0)
		cout << ans[i] << " ";
	cout <<  endl;
	return 0;
}
