#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#define MAXN 101
using namespace std;

struct cell {
    int value = 0;   //0 - empty, 1 - S, 2 - D 
	int left = 0;
    int top = 0;
    int right = 0;
	int bottom = 0;
};
int m;
int n;
int p;
int q;
int is_solve;
int x2;
int y2;
vector<pair<int, int>> vertices;
vector <set <int> > graf(MAXN * MAXN);
int matrix[MAXN][MAXN];
cell m_cell[MAXN][MAXN];


void build_graf(int x, int y, int prev)
{
	int current;
	if (-1 == matrix[x][y])
	{
		vertices.push_back(make_pair(x, y));
		current = vertices.size() - 1;
		matrix[x][y] = current;
		if (current)
		{
			graf[current].insert(prev);
			graf[prev].insert(current);
		}
	}
	else 
	{
		current = matrix[x][y];
		if (current)
		{
			graf[current].insert(prev);
			graf[prev].insert(current);
		}
		return;
	}
	if (x == x2 && y == y2)
		is_solve = current;
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
	int j;
	int v;
	int d;
	string str;
	queue <pair <int, int>> qu;

	for (int i1 = 0; i1 < MAXN; ++i1)
	{
		for (int j1 = 0; j1 < MAXN; ++j1)
			matrix[i1][j1] = -1;
	}

    n = 5; m = 5;// p = 0; q = 0; x1 = 1; y1 = 1; x2 = 2; y2 = 2;	
//	cin >> n >> m; //>> p >> q >> x1 >> y1 >> x2 >> y2;
	i = 0;
	while (++i <= 2 * n + 1)
	{
		getline(cin, str);
		j = 0;
		while (++j <= 2 * m + 1)
		{
			if (i % 2 && 0 == j % 2 && '-' == str[j - 1])
			{
				if (i < 2 * n + 1)
					m_cell[(i + 1) / 2][j / 2].top = 1;
				if (i > 2)
					m_cell[(i - 1) / 2][j / 2].bottom = 1;
			}
			if (0 == i % 2)
			{
				if (j % 2)
				{
					if ('|' == str[j - 1])
					{
						if (j < 2 * m + 1)
							m_cell[i / 2][(j + 1) / 2].left = 1;
						if (j > 2)
							m_cell[i / 2][(j - 1) / 2].right = 1;
					}
				}
				else 
				{
					if ('S' == str[j - 1])
						m_cell[i / 2][j / 2].value = 1;
					else if ('D' == str[j - 1])
					{
						m_cell[i / 2][j / 2].value = 2;
						vertices.push_back(make_pair(i / 2, j / 2));
					}
				}
			}
		}
	}
	cout << "m_cell \n ";
	for (int i1 = 1; i1 <= n; ++i1)
	{
		for (int j1 = 1; j1 <= m; ++j1)
			cout << m_cell[i1][j1].value << m_cell[i1][j1].left << m_cell[i1][j1].top << m_cell[i1][j1].right << m_cell[i1][j1].bottom<< " ";
		cout << "\n ";
	}
	cout << "m_cell D \n ";
	
	d = vertices.size();
	vector <pair<int, int>>  dist(m * n);
	for (auto v1: vertices)
	{
		
		dist[v1] = 0;
		qu.push(v1);
		while (!qu.empty())
		{
			auto v = qu.front();
			qu.pop();
			while
			for (int u : graf[v])
			{
				if (-1 == dist[u])
				{
					dist[u] = dist[v] + 1;
					if (matrix[x2][y2] == u)
					{
						cout <<  dist[u] << "\n";
						return 0;
					}
					qu.push(u);
				}
			}
		}
	return 0;
}
