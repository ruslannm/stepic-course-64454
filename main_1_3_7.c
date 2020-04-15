#include "stdio.h"
#define MAXN    200005

int main(void)
{
    int n;
    int m;
    int k;
    int i;
    int l;
    int r;
    int mid;
    long a[MAXN];

    scanf("%d %d", &n, &m);
    i = 0;

    while (i < n)
    {
        scanf("%d", &k);
        a[i++] =  k;
    }
    i = 0;
    while (i < m)
    {
        scanf("%d", &k);
        l = -1;
        r = n;
        while (l + 1 < r)
        {
            mid = (l + r) / 2;
            if (a[mid] > k)
                l = mid;
            else
                r = mid;
        }
        if (a[r] <= k && r < n)
            printf("%d\n", r + 1);
        else
            printf("NO SOLUTION\n");
        i++;        
    }
    return (0);
}
