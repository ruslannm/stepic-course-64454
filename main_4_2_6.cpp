#include <iostream>
#include <vector>

using namespace std;

vector<int> used(501, 0);
int cicle;

void dfs(const vector<vector<int> >& graf, int to, int from)
{
	used[to] = 1;
	for (auto u : graf[to])
	{
		if (1 == used[u] && u != from)
			cicle = 1;
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
		graf[v].push_back(u);
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
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
