#include <stdio.h>
#define N 200000000

unsigned long phi[N+1],chk[N+1][1];

void phiSieve();

int main(void)
{
    unsigned long t,i,n,l;
    phiSieve();
    scanf("%lu",&t);
    while(t--)
    {
        scanf("%lu",&n);
        if(chk[n][0]==0)
            printf("-1\n");
        else
            printf("%lu\n",chk[n][0]);
    }

    return 0;
}

void phiSieve()
{
    unsigned long long i,j;
    for(i=1;i<=N;i++)
        phi[i]=i;
    chk[1][0]=1;
    for(i=2;i<=N;i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(j=2*i;j<=N;j+=i)
                phi[j]=(phi[j]/i)*(i-1);
        }
        if(chk[phi[i]][0]==0)
            chk[phi[i]][0]=i;
    }
}
