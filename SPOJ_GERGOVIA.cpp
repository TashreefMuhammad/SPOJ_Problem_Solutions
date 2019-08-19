#include <stdio.h>

int main(void)
{
    long n,i,cost;
    while(1)
    {
        cost=0;
        scanf("%ld",&n);
        if(n==0)
            break;
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
            if(a[i]>0)
                cost+=a[i];
            else
                cost-=a[i];
            a[i+1]+=a[i];
        }
        printf("%ld\n",cost);
    }

    return 0;
}
