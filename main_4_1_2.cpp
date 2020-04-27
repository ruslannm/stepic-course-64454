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
	int s_size;
	char str[501];

	cin >> n >> m;
    //n = 4;
	vector <vector <int> > a(n + 1, vector <int> (n + 1, 0));
	i = -1;
	while (++i < m)
	{
		cin >> u >> v;
		a[u][v] = 1;
		a[v][u] = 1;
	}
/*
	a[1][1] = 0;
	a[1][2] = 1;
	a[1][3] = 0;
	a[1][4] = 0;
	a[2][1] = 1;
	a[2][2] = 0;
	a[2][3] = 1;
	a[2][4] = 1;
	a[3][1] = 0;
	a[3][2] = 1;
	a[3][3] = 0;
	a[3][4] = 0;
	a[4][1] = 0;
	a[4][2] = 1;
	a[4][3] = 0;
	a[4][4] = 0;
*/
	vector <int> s;
	i = 0;
	while (++i <= n)
	{
		j = 0;
		while (++j <= n)
		{
			if (a[i][j]) 
				s.push_back(j);
		}
		s_size = s.size();	
		cout << s_size << " ";
		j = -1;
		while (++j < s_size)
			cout << s[j] << " ";
		cout << "\n";
		s.clear();
	}
	return 0;
}
