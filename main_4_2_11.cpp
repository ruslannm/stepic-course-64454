#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 6 //100001

using namespace std;

vector<int> used(MAXN, 0);
int pos;
vector<int> solve;
int cicle;

void dfs(const vector<vector<int> >& graf, int to, int from)
{
	used[to] = 1;
	for (auto u : graf[to])
	{
		if (1 == used[u])
			cicle = 1;
		else if (0 == used[u])
			dfs(graf, u, to);
	}
	used[to] = 2;
	solve[--pos] = to;
}

int main()
{
	int n;
	int m;
	int i;
	int u;
	int v;

	cin >> n >> m;
//	n = 4; m = 4;
	vector <vector <int> > graf(n + 1);
	vector <vector <int> > matrix(n + 1, vector <int> (n + 1));

	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		graf[u].push_back(v);
		matrix[u][v] = 1;

	}
/*
	int test[4][2] = {{1,2}, {2,3}, {3,4}, {4, 1}};
	i = -1;
	while (++i < n)
	{
		graf[test[i][0]].push_back(test[i][1]);
		matrix[test[i][0]][test[i][1]] = 1;
	}
*/
	pos = n;
	solve.resize(n + 1);
	cicle = 0;
	i = 0;
	while (++i <= n)
	{
		if (0 == used[i])
			dfs(graf, i, 0);
		if (cicle)
		{
			cout << "NO\n";
			return 0;
		}
	}
	//cout << "YES\n";
	i = 0;
	while (++i < n)
	{
		auto result1 = find(graf[solve[i - 1]].begin(), graf[solve[i - 1]].end(), solve[i]);
 	    if (result1 == graf[solve[i - 1]].end()) 
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
