#include <iostream>
#include <vector>

using namespace std;

vector<int> used(20001, 0);
vector<int> component(20001, 0);

void dfs(const vector<vector<int> >& graf, int v, int l)
{
	used[v] = 1;
	component[v] = l;
	for (auto u : graf[v])
	{
		if (used[u])
			continue;
		dfs(graf, u, l);
	}
}

int main()
{
	int n;
	int m;
	int i;
	int j;
	int s_size;
	int u;
	int v;
	int l; //quant of component

	cin >> n >> m;
	vector <vector <int> > graf(n + 1);
	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		graf[u].push_back(v);
		graf[v].push_back(u);
	}
/*	cout << "size=" << graf.size() << '\n';
	i = 0;
	while (++i <= n)
	{
		cout << i << " : ";
		for(auto i2 : graf[i])
			cout << i2 << " ";
		cout << "\n";
	}
*/
	i = 0;
	l = 0;
	while (++i <= n)
	{
		if (!used[i])
		{
			++l;
			dfs(graf, i, l);
		}
	}
	cout << l << "\n";
	i = 0;
	while (++i <= n)
		cout << component[i] << " ";
	return 0;
}
