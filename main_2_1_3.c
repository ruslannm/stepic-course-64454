#include "stdio.h"

unsigned long long solve(unsigned long long a)
{
    unsigned long long rem;

    rem = a % 3;
    if (rem)
    {
		if ((a + 1) % 3)
			rem = 6148914691236517205U + solve(a + 1);
		else
			rem = 6148914691236517205U + (a + 1) / 3;
    }
	else
		rem = a / 3;	
    return (rem);
}

int main(void)
{
    unsigned long long a;
    unsigned long long rem;

    scanf("%llu", &a);
    printf("%llu\n", solve(a));
    return (0);
}
