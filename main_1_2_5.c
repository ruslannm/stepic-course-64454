#include "stdio.h"
#define MAXN    300005

long long an[MAXN];
long long qn[MAXN];

int main(void)
{
    int n;
    int q;
    long n_in;
    int i;
    int l;
    int r;

    scanf("%d %d", &n, &q);
    an[0] = 0;
    i = 1;
    while (i <= n)
    {
        scanf("%ld", &n_in);
        an[i] = an[i - 1] + n_in;
        i++;
    }
    i = 0; 
    l = 1;
    r = 1;
    while (i < q)
    {
        scanf("%d %d", &l, &r);
        qn[i] = an[r] - an[l - 1];
        i++;
    }
    i = 0; 
    while (i < q)
    {
        printf("%lld\n", qn[i]);
        i++;
    }
    return (0);
}