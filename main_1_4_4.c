#include "stdio.h"

unsigned long maxn(int w,  int h, unsigned long len)
{
    unsigned long ret;
    int min;
    int first;

    min = (w > h ? h : w);
    first = (len >= min ? 1 : 0);
    if (first)
    {
        len = len - min;
        ret = first + (len / h) + (len / w);
    }
    else
        ret = 0;    
    return (ret);
}

int main(void)
{
    unsigned long n;
    int x;
    int y;
    unsigned long l;
    unsigned long r;
    unsigned long mid;

    scanf("%lu %d %d", &n, &x, &y);
    l = 0;
    r = (x > y ? y : x) + n * (x > y ? x : y) * 2;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;
        if (maxn(x, y, mid) >= n)
                r = mid;
            else
               l = mid;
    }
    printf("%lu\n", r);
    return (0);
}
