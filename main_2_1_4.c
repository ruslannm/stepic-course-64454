#include "stdio.h"
#include "stdlib.h"

long *fill(long maxa)
{
    long i;
    long j;
    long *ar;
    
    ar = (long*)malloc(sizeof(long) * maxa + 2);
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
            {
                if (0 == ar[i * j]) 
                    ar[i * j] = i;
                j++;
            }
        }
        i++;
    }
    return (ar);
}

int main(void)
{
    long n;
    long *ar;
    long i;
    unsigned long ret;

    scanf("%ld", &n);
    ar = fill(n);
    ret = 0;
    i = 1;
    while (i <= n)
    {
        if (ar[i])
            ret += ar[i];
        i++;
    }
    printf("%ld\n", ret);
    free (ar);
    return (0);
}
