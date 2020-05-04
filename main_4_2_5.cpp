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
int n;

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

void del_number(int u, int v)
{
	int ret;

	for (int i = 0; i <= edges.size(); ++i)
	{
		if ((edges[i].first == u && edges[i].second == v) || (edges[i].first == v && edges[i].second == u))
			{
				edges_numbers.erase(i + 1);
				return ;
			}
	}
}


void dfs(const vector<vector<int> >& graf, int to, int from, vector<int> & edges_track, int edge)
{
	int tmp; 
	int count_edges;
	int count_vertices;

	
	edges_track[edge] = 1;
	add_number(to, from);
	count_edges = 0;
	for (int i = 1; i <= edges_track.size(); ++i)
	{
		if (edges_track[i] != 0)
			++count_edges;
	}
	used[to] = 1;
	count_vertices = 0;
	for (auto u : graf[to])
	{
		if (0 == used[u])
		{
			tmp = get_number(to, u);
			++count_vertices;
			if (edges_solve[tmp] && edges_track[tmp] == 0)
			{
				dfs(graf, u, to, edges_track, tmp);
			}
		}
	}
	tmp = 0;
	for (int i = 1; i <= edges_track.size(); ++i)
	{
		if (edges_track[i] != 0)
			++tmp;
	}
	if (count_vertices && tmp < count_edges + count_vertices)
	{
//		edges_track[edge] = 0;
		
//		del_number(to, from);
		for (int j = 0; j <= n; ++j)
			used[j] = 1;
	}
	//used[to] = 2;
}

int main()
{
	int m;
	int i;
	int u;
	int v;
	set<int> vertices;
	set<int> set_edges_solve;
	vector<int> edges_diff;
	int tmp;
	int q;

//	cin >> n >> m;
	n = 6; m = 10;
	vector <vector <int> > graf(n + 1);
/*	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		edges.push_back(make_pair(u, v));
		graf[u].push_back(v);
		graf[v].push_back(u);
	}
 */
    int edges_test[10][2] = {{1, 3},{3, 5}, {1, 6}, {1,5}, {1, 4}, {5, 6},{6, 4},{2, 6},{2, 1},{3, 2}};	
	for (int j = 0; j < m; ++j)
	{
		edges.push_back(make_pair(edges_test[j][0], edges_test[j][1]));
		graf[edges_test[j][1]].push_back(edges_test[j][0]);
		graf[edges_test[j][0]].push_back(edges_test[j][1]);
	}
//	cin >> q;
	q = 5;
	edges_solve.resize(m + 1);
/*	for (int j = 0; j <= m; ++j)
		edges_solve[j] = 0;
*/
	int edges_solve_test[] = {10,2,4,5,7};//{5, 3, 1, 8, 4};
	for (int j = 0; j < q; ++j)
	{
		edges_solve[edges_solve_test[j]] = 1;
		set_edges_solve.insert(edges_solve_test[j]);
		vertices.insert(edges[edges_solve_test[j] - 1].first);
		vertices.insert(edges[edges_solve_test[j] - 1].second);
	}
/*	for (int i= 1; i <= q; ++i)
	{
		cin >> tmp;
		edges_solve[tmp] = i;
		set_edges_solve.insert(tmp);
		vertices.insert(edges[tmp - 1].first);
		vertices.insert(edges[tmp - 1].second);
	}
*/
	if (q != n - 1)
    {
        cout << "NO";
        return 0;
    }
	vector<int> edges_track(m + 1, 0);
	for (int i1 : vertices)
	{
		used[0] = 2;
		for (int j = 1; j <= n; ++j)
			used[j] = 0;
		edges_numbers.clear();
		edges_diff.clear();
		for (int j = 0; j <= m; ++j)
			edges_track[j] = 0;

		dfs(graf, i1, 0, edges_track, 0);
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
