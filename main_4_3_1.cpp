#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main()
{
	int n;
	int m;
	int i;
	int u;
	int v;
	queue <int> q;
	vector <int> solve;

	cin >> n >> m;
//	n = 4; m = 6;
	vector <vector <int> > graf(n + 1);

	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		graf[u].push_back(v);
		graf[v].push_back(u);
	}
/*
	int test[6][2] = {{3,4}, {2,4}, {1,3}, {1, 2}, {1,4}, {2,3}};
	i = -1;
	while (++i < m)
	{
		graf[test[i][0]].push_back(test[i][1]);
		graf[test[i][1]].push_back(test[i][0]);
	}
*/
	vector<int> used(n + 1, 0);
	cin >> v;
//v = 4;
	used[v] = 1;
	q.push(v);
	solve.push_back(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (auto u: graf[v])
		{
			if (used[u])
				continue;
			used[u] = 1;
			q.push(u);
			solve.push_back(u);
		}
	}
	//cout << "YES\n";
	i = -1;
	while (++i < n)
		cout << solve[i] << " ";
	cout << "\n";
	return 0;
}
