#include "stdio.h"
#include "stdlib.h"
#define MAXN 2097152

long *fill(long maxa)
{
    long i;
    long j;
    long *ar;
    
    ar = (long*)malloc(sizeof(long) * MAXN + 2);
    i = 2;    
    while (i <= maxa)
        ar[i++] = 0;
    i = 2;
    while (i * i <= maxa)
    {
        if (0 == ar[i])
        {   
            j = i;
            while (j * i <= maxa)
                ar[i * j++] = 1;
        }
        i++;
    }
    return (ar);
}

int main(void)
{
    long a;
    long b;
    long c;
    long *ar;
    long maxa;
    long common;
    long simple;
    unsigned long ret;

    scanf("%ld %ld %ld", &a, &b, &c);
    if (a > b && a > c)
        maxa = a;
    else if (b > a && b > c)
        maxa = b;
    else 
        maxa = c;
    ar = fill(maxa);
    simple = maxa;
    common = 1;
    while (simple > 1)
    {
        if (ar[simple] == 0)
        {
            while (a % simple == 0 &&  b % simple == 0 && c % simple == 0)
            {
                common *= simple;
                a /= simple;
                b /= simple;
                c /= simple;
            }
        }
        simple--;
    }
    ret = (common * a * b * c) / (a * b + b * c + a * c);
    printf("%ld\n", ret);
    return (0);
}
