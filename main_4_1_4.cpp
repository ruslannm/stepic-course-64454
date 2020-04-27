#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int i;
	int j;
	int v;
	int q;

	cin >> n;
	vector <vector <int> > a(n + 1, vector <int> (n + 1, 0));
	i = 0;
	while (++i <= n)
	{
		cin >> q;
		j = 0;
		while (++j <= q)
		{
			cin >> v;
			a[i][v] = 1;
			a[v][i] = 1;
		}
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
