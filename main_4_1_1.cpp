#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int i;
	int j;
	int s_size;
	char str[501];

	cin >> n;
    //n = 4;
	vector <vector <int> > a(n + 1, vector <int> (n + 1));
	i = 0;
	while (++i <= n)
	{
		scanf("%s", str);
		j = -1;
		while (++j <= n)
		{
			if (str[j] == '0')
				a[i][j + 1] = 0;
			else
				a[i][j + 1] = 1;
		}
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
