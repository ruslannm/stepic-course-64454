#include <iostream>
#define MAXN	301

using namespace std;

int f_sort(long long *p, long long *w, long long *c, int i)
{
	if (w[p[i]] == 0 && w[p[i]] != 0)
		return 0;
	if (w[p[i]] == 0 && w[p[i]] == 0 && c[p[i]] < c[p[i]])
		return 1;
	if (c[p[i]] * w[p[i - 1]] < c[p[i - 1]] * w[p[i]]) 
		return 1;
	return 0;
}

int main()
{
	int n;
	int s;
	int i;
	int j;
	int k;
	int tmp;
	int ret;
	long long w[MAXN];
	long long c[MAXN];
	long long p[MAXN];  //order

	//cin >> s >> n;
	s = 8; n =4;
	i = -1;
	while (++i <= n)
		p[i] = i;
	i = 0;
/*	while (++i <= n)
		cin >> w[i];
	i = 0;
	while (++i <= n)
		cin >> c[i];
*/
	w[1] = 7;
	w[2] = 0;
	w[3] = 0;
	w[4] = 1;
	c[1] = 9;
	c[2] = 2;
	c[3] = 2;
	c[4] = 2;

	i = n;
	while (i > 1)
	{
		k = -1;
		while (++k <= n)
			cout << p[k] << " ";
		cout << endl;
//		
		k = 0;
		j = 1;
		while (++j <= i)
		{
			if (f_sort(p, w, c, j))
			{
				tmp = p[j -1];
				p[j - 1] = p[j];
				p[j] = tmp;
				k = j;
			}
		}
		i = k;
	}
	i = n;
	tmp = 0;
	ret = 0;
	while (i > 0)
	{
		if (w[p[i]] < s)
		{
			if (tmp + w[p[i]] > s)
			{
				ret += ((s - tmp) * c[p[i]] + w[p[i]] - 1) / w[p[i]];
				break;
			}
			else
			{
				tmp += w[p[i]];
				ret += c[p[i]];
			}
		}
		i--;
	}
	cout << ret << endl;
	return 0;
}
