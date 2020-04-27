#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int m;
	int i;
	int j;
	int u;
	int v;

	cin >> n >> m;
	vector <vector <int> > a(n + 1, vector <int> (n + 1, 0));
	i = -1;
	while (++i < m)
	{
		cin >> u >> v;
		a[u][v] = 1;
		a[v][u] = 1;
	}
	i = 0;
	while (++i <= n)
	{
		j = 0;
		while (++j <= n)
			cout << a[i][j];
		cout << "\n";
	}
	return 0;
}
