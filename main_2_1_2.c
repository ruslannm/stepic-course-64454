#include "stdio.h"

int check_simple(long a)
{
    long i;
    
    if (a == 2)
        return (1);
    if (a % 2 == 0)
        return (0);
    i = 3;    
    while (i * i <= a)
    {
        if (a % i == 0)
            return (0);
        i = i + 2;
    }
    return (1);
}

int main(void)
{
    long a;

    scanf("%ld", &a);
    printf("%d\n", check_simple(a));
    return (0);
}
