#include "stdio.h"

int main(void)
{
    int n;
    int m;
    int k;
    int i;
    int l;
    int r;
    int mid;

    scanf("%d %d", &n, &k);
    l = -1;
    r = n;
    i = 0;
    while (i < k)
    {
        scanf("%d", &m);
        mid = (l + r) / 2;
        if (m == 0)
            l = mid;
        else
            r = mid;
        if (l + 1 == r)
            break ;
        i++;        
    }
    printf("%d\n", r);
    return (0);
}
