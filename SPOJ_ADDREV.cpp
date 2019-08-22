#include <stdio.h>

int main(void)
{
    int n,v1,v2,v3,v4;
    scanf("%d",&n);
    while(n--)
    {
        v3=v4=0;
        scanf("%d %d",&v1,&v2);
        while(v1)
        {
            v3=10*v3+(v1%10);
            v1/=10;
        }
        while(v2)
        {
            v4=10*v4+(v2%10);
            v2/=10;
        }
        v1=v3+v4;
        v2=0;
        while(v1)
        {
            v2=10*v2+(v1%10);
            v1/=10;
        }
        printf("%d\n",v2);
    }
    return 0;
}
