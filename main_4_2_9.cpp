#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> used(501, 0);
int pos;
vector<int> solve;
int cicle;

void dfs(const vector<vector<int> >& graf, int to, int from)
{
	used[to] = 1;
	solve.push_back(to);
	for (auto u : graf[to])
	{
		if (0 == used[u])
			dfs(graf, u, to);
	}
	solve[pos--] = to;
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
	pos = n;
	solve.resize(n);
	i = 0;
	while (++i <= n)
	{
		if (0 != used[i])
			dfs(graf, i, 0);
	}
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



	cout << "NO";
	return 0;
}
