#include "stdio.h"
#define	REM	1000003

long long fibo(long long a)
{
	long long c;
	long long c1;
	long long c2;
	int i;

	if (a == 1)
		return (1);
	c2 = 1;
	c1 = 1;
	i = 1;
	while (++i <= a)
	{
		if (c1 > REM && c2 > REM)
		{
			c1 = c1 - REM;
			c2 = c2 - REM;
		}
		c = c1 + c2;
		c2 = c1;
		c1 = c;
	}
	return (c % REM);
}

int main(void)
{
    long n;

    scanf("%ld", &n);
    printf("%lld\n", fibo(n));
    return (0);
}
