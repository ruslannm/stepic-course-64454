#include "stdio.h"
#define MAXN    100005

int main(void)
{
    int n;
    int a[MAXN];
    int i;
    int maxi;
    int maxa;

    scanf("%d\n", &n);
    i = 0;
    maxi = 1;
    maxa = 0;
    while (i < n)
    {
        scanf("%d", &a[i]);
        if (a[i] > maxa)
        {
            maxi = i + 1;
            maxa = a[i];
        }
        i++;
    }
    printf("%d\n", maxi);
    return (0);
}