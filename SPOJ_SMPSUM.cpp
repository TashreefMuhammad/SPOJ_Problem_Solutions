#include <stdio.h>

int main(void)
{
    long long a,b,i,out=0;
    scanf("%lld %lld",&a,&b);
    for(i=a;i<=b;i++)
        out+=i*i;
    printf("%lld",out);
    return 0;
}
