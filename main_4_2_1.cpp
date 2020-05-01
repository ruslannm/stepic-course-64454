#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<vector<int>> s;
vector<int> used;
list<int> visit;

void dfs(int v)
{
	used[v] = 1;
	visit.push_back(v);
	for (auto u : s[v])
	{
		if (used[u])
			continue;
		dfs(u);
		visit.push_back(v);	
	}
}

int main()
{
	int n;
	int m;
	int i;
	int j;
	int s_size;
	int u;
	int v;
	int ustart;

	//cin >> n >> m;
    n = 5; m = 7;
	vector <vector <int> > a(n + 1, vector <int> (n + 1, 0));
/*	i = -1;
	while (++i < m)
	{
		cin >> u >> v;
		a[u][v] = 1;
		a[v][u] = 1;
	}
	cin >> ustart;
*/
	ustart = 4;
	a[1][1] = 0;
	a[1][2] = 1;
	a[1][3] = 1;
	a[1][4] = 1;
	a[1][5] = 0;
	a[2][1] = 1;
	a[2][2] = 0;
	a[2][3] = 0;
	a[2][4] = 1;
	a[2][5] = 0;
	a[3][1] = 1;
	a[3][2] = 0;
	a[3][3] = 0;
	a[3][4] = 1;
	a[3][5] = 1;
	a[4][1] = 1;
	a[4][2] = 1;
	a[4][3] = 1;
	a[4][4] = 0;
	a[4][5] = 1;
	a[5][1] = 0;
	a[5][2] = 0;
	a[5][3] = 1;
	a[5][4] = 1;
	a[5][5] = 0;


	s.resize(n + 1);
	used.resize(n + 1, 0);
	i = 0;
	while (++i <= n)
	{
		j = 0;
		while (++j <= n)
		{
			if (a[i][j]) 
				s[i].push_back(j);
		}
	}
	i = 0;
	while (++i <= n)
	{
		cout << i << " : ";
		for(auto i2 : s[i])
			cout << i2 << " ";
		cout << "\n";
	}
	dfs(ustart);
	cout << visit.size() << "\n";
	for (auto u: visit)
		cout << u << " ";
	return 0;
}
