#include <iostream>

using namespace std;

int main()
{
	int n;
	int s;
	int i;
	int a;
	int ret;

	cin >> s >> n;
	ret = 0;
	i = 0;
	while (++i <= n)
	{
		cin >> a;
		ret += a;
		if (ret >= s)
			break ;
	}
    if (ret > s)
		ret = s;
	cout << ret << endl;
	return 0;
}
