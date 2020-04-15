#include "stdio.h"
#include "math.h"

const long double EPS = 1e-16;

long double f(int n, int *a, long double x)
{
    long double ax[5];
    long double tmp;
    int i;

    i = 1;
    tmp = x;
    while (i <= n)
    {
        ax[i] = (a[i] ? a[i] * tmp : 0);
        tmp = tmp * x;
        i++;
    }
    while (i <= 4)
        ax[i++] = 0;
    return (a[0] + ax[1] + ax[2] + ax[3] + ax[4]);
}
/*
** h - hypotenuse
*/

long double   h(long double k1, long double k2)
{
    long double ret;

    ret = k1 * k1 + k2 * k2;
    ret = sqrt(ret);
    return (ret);
}

int main(void)
{
    int cx, cy ,cd;
    int n;
    int k;
    int x;
    int tmpx;
    int i;
    long double l;
    long double r;
    long double mid;
    long double y;
    int a[5];
    int solveleft;

    scanf("%d %d %d", &cx, &cy, &cd);
    scanf("%d", &n);
    i = n;
    while (i >= 0)
    {
        scanf("%d", &k);
        a[i--] =  k;
    }
    i = n;
    while (++i <= 4)
    {
        a[i] =  0;
    }
    scanf("%d", &x);
    solveleft = 0;
    tmpx = x;
    y = f(n, a, tmpx);
    while (tmpx > cx - cd)
    {
        if (h(tmpx - cx, y - cy) > cd)
        {
            solveleft = 1;
            break ;
        }
        y = f(n, a, --tmpx);
    }
    l = tmpx;
    r = x;
    if (0 == solveleft)
    {
        tmpx = x;
        y = f(n, a, tmpx);
        while (tmpx < cx + cd)
        {
            if (h(tmpx - cx, y - cy) > cd)
                break ;
            y = f(n, a, ++tmpx);
        }
        l = x;
        r = tmpx;
    }
    i = 0;
    while (i < 100)
    {
        mid = (l + r) / 2;
        y = f(n, a, mid);
        if (h(mid - cx, y - cy) - cd > EPS)
        {
            if (solveleft)
                l = mid;
            else
               r = mid;
        }    
        else
        {
            if (solveleft)
                r = mid;
            else
               l = mid;
        }    
        i++;
    }
    printf("%.15Lf\n", (r + l) / 2);
    return (0);
}
