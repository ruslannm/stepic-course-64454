#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> used(501, 0);
int cicle;
int start_cicle;
vector<int> solve(501, 0);

void dfs(const vector<vector<int> >& graf, int to, int from)
{
	used[to] = 1;
	solve.push_back(to);
	for (auto u : graf[to])
	{
		if (1 == cicle)
			return;
		if (1 == used[u])
		{
			cicle = 1;
			start_cicle = u;
		}
		else if (0 == used[u])
			dfs(graf, u, to);
	}
	used[to] = 2;
}

int main()
{
	int n;
	int m;
	int i;
	int u;
	int v;

	cin >> n >> m;
	vector <vector <int> > graf(n + 1);
	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		graf[u].push_back(v);
	}
	cicle = 0;
	i = 0;
	while (++i <= n)
	{
		used[0] = 0;
		for (int j = 1; j <= n; ++j)
			used[j] = 0;
		dfs(graf, i, 0);
		if (cicle)
		{
			int j = solve.size();
			int q = 1;
			while (solve[j - q] != start_cicle)
				++q;
			cout << "YES\n" << q << "\n";
			while (q)
			{
				cout << solve[j - q] << " ";
				--q;
			}
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
