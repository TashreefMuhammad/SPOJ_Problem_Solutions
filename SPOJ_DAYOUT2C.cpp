#include <stdio.h>
int main(void)
{
    int t,i;
    scanf("%d",&t);
    unsigned long n[t],j;
    int ans[t];
    for(i=0;i<t;i++)
    {
        scanf("%lu",&n[i]);
        ans[i]=1;
        if(n[i]<=1)
            ans[i]=0;
        else
            for(j=2;j*j<=n[i];j++)
                if(n[i]%j==0)
                 {
                    ans[i]=0;
                    break;
                 }
    }
    for(i=0;i<t;i++)
    {
        if(ans[i]==1)
            printf("%lu is a prime\n",n[i]);
        else
            printf("%lu is not a prime\n",n[i]);
    }
    return 0;
}
