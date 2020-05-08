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
	int d;
	queue <int> q;

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
	d = 0;
	vector <vector <int> > dist(n + 1, vector <int> (n + 1, - 1));
	i = 0;
	while (++i <= n)
	{
		v = i;
		dist[i][v] = 0;
		q.push(v);
		while (!q.empty())
		{
			v = q.front();
			q.pop();
			for (auto u: graf[v])
			{
				if (-1 == dist[i][u])
				{
					dist[i][u] = dist[i][v] + 1;
					d += dist[i][u];
					q.push(u);
				}
			}
		}
	}
 	cout << d / 2 << "\n";
	return 0;
}
