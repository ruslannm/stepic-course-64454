#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> used(501, 0);
vector<pair<int, int>> edges;
set<int> edges_numbers;
vector<int> edges_solve;

int get_number(int u, int v)
{
	int ret;

	for (int i = 0; i <= edges.size(); ++i)
	{
		if ((edges[i].first == u && edges[i].second == v) || (edges[i].first == v && edges[i].second == u))
			{
				return (i + 1);
			}
	}
	return (0);
}

void add_number(int u, int v)
{
	int ret;

	for (int i = 0; i <= edges.size(); ++i)
	{
		if ((edges[i].first == u && edges[i].second == v) || (edges[i].first == v && edges[i].second == u))
			{
				edges_numbers.insert(i + 1);
				return ;
			}
	}
}

void dfs(const vector<vector<int> >& graf, int to, vector<int> & edges_track)
{
	int tmp; 

	used[to] = 1;
	for (auto u : graf[to])
	{
		if (0 == used[u])
		{
			tmp = get_number(to, u);
			if (edges_solve[tmp] && edges_track[tmp] == 0)
			{
				edges_track[tmp] = 1;
				add_number(u, to);
				dfs(graf, u, edges_track);
			}
		}
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
	set<int> vertices;
	set<int> set_edges_solve;
	vector<int> edges_diff;
	int tmp;
	int q;

	cin >> n >> m;
//	n = 6; m = 10;
	vector <vector <int> > graf(n + 1);
	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		edges.push_back(make_pair(u, v));
		graf[u].push_back(v);
		graf[v].push_back(u);
	}
/*
	u = 5; v = 3;
	edges.push_back(make_pair(u, v));
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 4; v = 6;
	edges.push_back(make_pair(u, v));
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 1; v = 2;
	edges.push_back(make_pair(u, v));
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 6; v = 5;
	edges.push_back(make_pair(u, v));
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 3; v = 2;
	edges.push_back(make_pair(u, v));
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 6; v = 1;
	edges.push_back(make_pair(u, v));
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 1; v = 4;
	edges.push_back(make_pair(u, v));
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 1; v = 3;
	edges.push_back(make_pair(u, v));
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 2; v = 6;
	edges.push_back(make_pair(u, v));
	graf[u].push_back(v);
	graf[v].push_back(u);
	u = 1; v = 5;
	edges.push_back(make_pair(u, v));
	graf[u].push_back(v);
	graf[v].push_back(u);
*/
	cin >> q;
//	q = 5;
	edges_solve.resize(m + 1);
	for (int j = 0; j <= m; ++j)
		edges_solve[j] = 0;
/*	edges_solve[9] = 1;
	set_edges_solve.insert(9);
		vertices.insert(edges[9 - 1].first);
		vertices.insert(edges[9 - 1].second);
	edges_solve[1] = 2;
	set_edges_solve.insert(1);
		vertices.insert(edges[1 - 1].first);
		vertices.insert(edges[1 - 1].second);
	edges_solve[7] = 3;
	set_edges_solve.insert(7);
		vertices.insert(edges[7 - 1].first);
		vertices.insert(edges[7 - 1].second);
	edges_solve[4] = 4;
	set_edges_solve.insert(4);
		vertices.insert(edges[4 - 1].first);
		vertices.insert(edges[4 - 1].second);
	edges_solve[8] = 5;
	set_edges_solve.insert(8);
		vertices.insert(edges[8 - 1].first);
		vertices.insert(edges[8 - 1].second);
*/
	for (int i= 1; i <= q; ++i)
	{
		cin >> tmp;
		edges_solve[tmp] = i;
		set_edges_solve.insert(tmp);
		vertices.insert(edges[tmp - 1].first);
		vertices.insert(edges[tmp - 1].second);
	}
	vector<int> edges_track(m + 1, 0);
	for (int i1 : vertices)
	{
		used[0] = 2;
		for (int j = 1; j <= 500; ++j)
			used[j] = 0;
		edges_numbers.clear();
		edges_diff.clear();
		for (int j = 0; j <= m; ++j)
			edges_track[j] = 0;

		dfs(graf, i1, edges_track);
		set_symmetric_difference(set_edges_solve.begin(), set_edges_solve.end(), edges_numbers.begin(), edges_numbers.end(), back_inserter(edges_diff)); 
		if (edges_diff.size() == 0)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
