#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 5//101
using namespace std;


int m;
int n;
int p;
int q;
int is_solve;
int x2;
int y2;
vector<pair<int, int>> vertices;
//vector <vector <int> > graf(MAXN * MAXN);
int matrix[MAXN][MAXN];
int graf[MAXN][MAXN];

void build_graf(int x, int y, int prev)
{
	if (-1 == matrix[x][y])
		vertices.push_back(make_pair(x, y));
	int current = vertices.size() - 1;
	if (x == x2 && y == y2)
		is_solve = current;
	if (current)
	{
//		graf[current].push_back(prev);
//		graf[prev].push_back(current);
		graf[current][prev] = 1;
		graf[prev][current] = 1;
	}
	if (0 == matrix[x][y])
		return;
	matrix[x][y] = 0;
	if (x + p <= m && y + q <= n)
		build_graf(x + p, y + q, current);
	if (x + p <= m && y - q > 0)
		build_graf(x + p, y - q, current);
	if (x - p > 0 && y + q <= n)
		build_graf(x - p, y + q, current);
	if (x - p > 0 && y - q > 0)
		build_graf(x - p, y - q, current);
	if (x + q <= m && y + p <= n)
		build_graf(x + q, y + p, current);
	if (x + q <= m && y - p > 0)
		build_graf(x + q, y - p, current);
	if (x - q > 0 && y + p <= n)
		build_graf(x - q, y + p, current);
	if (x - q > 0 && y - p > 0)
		build_graf(x - q, y - p, current);
}

int main()
{
	int x1;
	int y1;
	int i;
	int u;
	int v;
	int d;
	queue <int> qu;

	for (int i1 = 0; i1 <= 100; ++i1)
	{
		for (int j1 = 0; j1 <= 100; ++j1)
		{
			matrix[i1][j1] = -1;
			graf[i1][j1] = 0;
		}
	}
    m = 4; n = 4; p = 1; q = 1; x1 = 1; y1 = 1; x2 = 3; y2 = 3;	
//	cin >> m >> n >> p >> q >> x1 >> y1 >> x2 >> y2;
	is_solve = -1;
	build_graf(x1, y1, 0);
	if (is_solve < 1)
	{
		cout << is_solve << "\n";
		return 0;
	}

	d = 0;
	n = vertices.size();
	vector <int>  dist(n,- 1);
	i = -1;
	while (++i < n)
	{
		v = i;
		dist[v] = 0;
		qu.push(v);
		while (!qu.empty())
		{
			v = qu.front();
			qu.pop();
			u = -1;
			while (++u <= n)
			{
				if (graf[v][u] && -1 == dist[u])
				{
					dist[u] = dist[v] + 1;
					if (u == is_solve)
					{
						cout <<  dist[u] << "\n";
						return 0;
					}
					qu.push(u);
				}
			}
		}
	}
	return 0;
}
