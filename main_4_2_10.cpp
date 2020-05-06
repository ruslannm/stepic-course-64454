#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 6 //200001

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

//	cin >> n >> m;
	n = 5; m = 8;
	vector <vector <int> > graf(n + 1);
/*	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		graf[u].push_back(v);
	}
*/
	vector <int> test(n + 1);
/*	i = -1;
	while (++i < n)
	{
		cin >> u;
		test[i]= u;
	}
*/
	int test1[8][2] = {{5,4}, {2,3}, {5,3}, {2, 1}, {4,2}, {5,2}, {4,1}, {5,1}};
	i = -1;
	while (++i < m)
	{
		graf[test1[i][0]].push_back(test1[i][1]);
	}
	test[0] = 5;
	test[1] = 4;
	test[2] = 2;
	test[3] = 3;
	test[4] = 1;

//
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
	vector <int> used1(MAXN, 0);
	i = 0;
	used1[test[i]] = 1;
	while (++i < n)
	{
		for (int j : graf[test[i]])
		{
			if (used1[j])
			{
				cout << "NO\n";
				return 0;
			}
		}
		used1[test[i]] = 1;
	}
	
	cout << "YES\n";
	return 0;
}
