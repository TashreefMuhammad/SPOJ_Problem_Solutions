#include <stdio.h>

int main(void)
{
    int t,n,sum,i,in;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        sum=0;
        while(n--)
        {
            scanf("%d",&in);
            sum+=in;
        }
        printf("Case %d: %d\n",i+1,sum);
    }

    return 0;
}
