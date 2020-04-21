#include <iostream>
#define MAXN	301

using namespace std;

int f_sort(long long *p, long long *w, long long *c, int i)
{
	int pi;
	int pi1;
	int ret;

	ret = 0;
	pi = p[i];
	pi1 = p[i - 1];

	if (c[pi1] * w[pi] > c[pi] * w[pi1]) 
		ret = 1;
	return (ret);
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

	cin >> s >> n;
	i = -1;
	while (++i <= n)
		p[i] = i;
	i = 0;
	while (++i <= n)
		cin >> w[i];
	i = 0;
	while (++i <= n)
		cin >> c[i];

	i = n;
	while (i > 1)
	{
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
