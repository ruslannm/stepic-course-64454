#include "stdio.h"
#define MAXN    10000005
#define MOD     1791791791

long long an[MAXN];

int main(void)
{
    int n;
    int i;
    long long cur;
    int a;
    int b;
    int maxi1;
    int maxi2;
    long long maxa;

    scanf("%d\n", &n);
    scanf("%lld", &cur);
    scanf("%d", &a);
    scanf("%d", &b);

    maxi1 = 1;
    maxa = 0;
    i = 0;
    while (i < n)
    {
        cur = (cur * a + b) % MOD;
        an[i] = cur;
        if (an[i] > maxa)
        {
            maxi1 = i + 1;
            maxa = an[i];
        }
        i++;
    }
    maxi2 = 1;
    maxa = 0;
    i = 0; 
    while (i < n)
    {
        if (i + 1 != maxi1 && an[i] > maxa)
        {
            maxi2 = i + 1;
            maxa = an[i];
        }
        i++;
    }

    printf("%d %d\n", maxi1, maxi2);
    return (0);
}