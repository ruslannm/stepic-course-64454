#include <iostream>
#include <vector>
#include <algorithm>
#define MAXD    1e18L

using namespace std;

int main()
{
	int n;
	int k;
	int i;
	int j;
	int d;

	cin >> n >> k;
	//n = 5; k = 2;
	vector <long long> ar(n + 1, 0);
	vector <long long> dp(n + 1, 0);
	vector <int> pref_i(n + 1, 0);  // i-coordinate best parent for current dp
	
	vector <int> parent_i(n + 1, 0);
	i = 0;
	while (++i <= n)
		cin >> ar[i];
	/*ar[1] = 4;
	ar[2] = 7;
	ar[3] = 6;
	ar[4] = 6;
	ar[5] = 6;*/
    i = 0;
    while (++i <= n)
    {
		if (pref_i[i - 1] > i - k)
		{
			dp[i] = min(dp[pref_i[i - 1]], dp[i - k]);
			if (dp[i] == dp[pref_i[i - 1]])
			{
				pref_i[i] = pref_i[i - 1];
				parent_i[i] = pref_i[i - 1];	
			}
			else
			{
				pref_i[i] = i - k;
				parent_i[i] = i - k;	
				/* code */
			}
			
/*			if (dp[i] < dp[i - 1] - ar[i])
				pref_i[i] = i;
			else
*/				pref_i[i] = pref_i[i - 1];		
//			parent_i[i] = pref_i[i - 1];	
		}
		else
		{
			dp[i] = dp[i - k];
			parent_i[i] = pref_i[i - 1];
			pref_i[i] = i;			
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
