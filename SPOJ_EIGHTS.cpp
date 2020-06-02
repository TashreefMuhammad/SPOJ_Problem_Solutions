#include <stdio.h>

int main(void)
{
    unsigned long long t, in;

    scanf("%llu", &t);

    while(t--)
    {
        scanf("%llu", &in);
        printf("%llu\n",192+(in - 1)*250);
    }

    return  0;
}
