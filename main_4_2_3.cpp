#include <iostream>
#include <vector>

using namespace std;

vector<int> used(501, 0);
int reverse_edge;

void dfs(const vector<vector<int> >& graf, int to, int from)
{
	used[to] = 1;
	for (auto u : graf[to])
	{
		if (0 == used[u])
			dfs(graf, u, to);
		else if (1 == used[u] && u != from)
			++reverse_edge;
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
	//n = 6; m = 5;
	vector <vector <int> > graf(n + 1);
	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		graf[u].push_back(v);
		graf[v].push_back(u);
	}

/*
	u = 1; v=6;
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 4; v=1;
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 6; v=3;
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 5; v = 1;
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 2; v=4;
	graf[u].push_back(v);
	graf[v].push_back(u);
*/
	reverse_edge = 0;
	used[0] = 2;
	dfs(graf, 1, 0);
	cout << reverse_edge << "\n";
	return 0;
}
