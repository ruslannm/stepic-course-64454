#include "stdio.h"

long long maxn(long long w,  long long h, long long len)
{
    long long ret;

    ret = (len / h) * (len / w);
    return (ret);
}

int main(void)
{
    long long w;
    long long h;
    long long n;
    int i;
    long long l;
    long long r;
    long long mid;

    scanf("%lld %lld %lld", &w, &h, &n);
    l = 0;
    if (w > h)
        r = w * n;
    else
        r = h * n;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;
        if (maxn(w, h, mid) >= n)
                r = mid;
            else
               l = mid;
        i++;
    }
    printf("%lld\n", r);
    return (0);
}
