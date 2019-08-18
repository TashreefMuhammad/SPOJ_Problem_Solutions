#include <stdio.h>
#define N 10000000
#define M 1000000007

unsigned long phi[N+1],fact[N+1],primes[N+1];

void phiSieve();

int main(void)
{
    long long t,i,n,f,g;
    phiSieve();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        f=primes[n]-phi[n];
        if(f<0)
            f=0;
        g=phi[n];
        for(i=1;i<fact[f];i++)
            g=(g*phi[n])%M;
        printf("%lld\n",g);
    }

    return 0;
}

void phiSieve()
{
    unsigned long i,j;
    for(i=0;i<=N;i++)
        phi[i]=i;
    fact[0]=fact[1]=1;
    primes[0]=primes[1]=0;
    for(i=2;i<=N;i++)
    {
        fact[i]=fact[i-1]*i;
        if(phi[i]==i)
        {
            phi[i]=i-1;
            primes[i]=primes[i-1]+1;
            for(j=2*i;j<=N;j+=i)
                phi[j]=(phi[j]/i)*(i-1);
        }
        else
            primes[i]=primes[i-1];
    }
}
