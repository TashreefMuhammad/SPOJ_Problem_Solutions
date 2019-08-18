#include <stdio.h>
#include <vector>
#define N 1000000

using namespace std;

vector <unsigned long long> ar[N];
unsigned long phi[N+1],depth[N+1];

void phiSieve();

int main(void)
{
    unsigned long t,i,m,n,k,out,l;
    phiSieve();
    scanf("%lu",&t);
    while(t--)
    {
        out=0;
        scanf("%lu %lu %lu",&m,&n,&k);
        l=ar[k].size();
        for(i=0;i<l && ar[k][i]<=n;i++)
            if(ar[k][i]>=m && ar[k][i]<=n)
                out++;
        printf("%lu\n",out);
    }

    return 0;
}

void phiSieve()
{
    unsigned long i,j;
    for(i=0;i<=N;i++)
        phi[i]=i;
    for(i=2;i<=N;i++)
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(j=2*i;j<=N;j+=i)
                phi[j]=(phi[j]/i)*(i-1);
        }
    depth[1]=0;
    ar[0].push_back(1);
    for(i=2;i<=N;i++)
    {
        j=i;
        while(phi[j]!=1)
        {
            j=phi[j];
            depth[i]++;
        }
        depth[i]++;
        ar[depth[i]].push_back(i);
    }
}
