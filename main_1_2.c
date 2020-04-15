#include "stdio.h"
#define MAXN    100005

int main(void)
{
    int n;
    int a[MAXN];
    int i;
    long ret;

    scanf("%d\n", &n);
    i = 0;
    ret = 0;
    while (i < n)
    {
        scanf("%d", &a[i]);
        ret += a[i];
        i++;
    }
    printf("%ld\n", ret);
    return (0);
}