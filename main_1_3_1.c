#include "stdio.h"
#define MAXN    100005

int ft_count(int n, int *a)
{
    int l;
    int r;
    int mid;
    int ret;

    ret = 0;
    l = -1;
    r = n;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;
        if (a[mid] == 0)
            l = mid;
        else
            r = mid;
        ret++;        
    }
    return (ret);
}

int main(void)
{
    int n;
    int m;
    int k;
    int i;
    int j;
    int ret;
    int a[MAXN];
    int q[MAXN];

    scanf("%d %d", &n, &m);
    i = 0;
    while (i < n)
        a[i++] = 0;
    i = 0;
    while (i < m)
    {
        scanf("%d", &k);
        j = k;
        while (--j >= 0 && a[j] == 1)
            a[j] = 0;
        j = k - 1;
        while (++j < n && a[j] == 0)
            a[j] = 1;
        q[i] = ft_count(n, a);
        i++;
    }
    i = 0;
    while (i < m)
            printf("%d\n", q[i++]);
    return (0);
}
