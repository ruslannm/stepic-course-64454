#include "stdio.h"
#define MAXN        300005
#define MIN(a, b)   (a < b ? a : b)
#define MAX(a, b)   (a > b ? a : b)

int main(void)
{
    int n;
    long n_in;
    int i;
    long long ret;
    long long min;
    long long sum;

    scanf("%d", &n);
    i = 0;
    while (i < n)
    {
        scanf("%ld", &n_in);
        if (i == 0)
        {
            ret = n_in;
            min = 0;
            sum = 0;
        }
        sum += n_in;
        ret = MAX(ret, sum - min);
        min = MIN(min, sum);
        i++;
    }
    printf("%lld\n", ret);
    return (0);
}