#include "stdio.h"

int check20(long i)
{
    int k;
    int a[10] = {0,0,0,0,0,0,0,0,0,0};

    k = 1;
    while ( k < i)
        k *= 10;
    k = k / 10;
    while (k > 0)
    {
        if ((i / k) % 10 == 0 || (i / k) % 10 == 2)
            return (1);
        a[(i / k) % 10]++;
        k = k / 10;
    }
    k = 0;
    while (k < 10)
    {
        if (a[k++] > 1)
            return (1);
    }
    return (0);
}

int main(void)
{
    long n;

    scanf("%ld", &n);
    n++;
    if (n > 100000000)
    {
        printf("-1\n");
        return (0);
    }
    while (check20(n))
    {
        n++; 
        if (n > 100000000)
        {
            printf("-1\n");
            return (0);
        }
    }
    printf("%ld\n", n);
    return (0);
}