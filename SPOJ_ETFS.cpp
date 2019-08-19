#include <stdio.h>
#include <math.h>
#define N 10000000

long long var[N/32+1];
long long primes[N/10];
long long k;

void segmenthandle(unsigned long long a,unsigned long long b);
void bsieve();
bool checkprime(long long n,long long pos);
long long setnotprime(long long n,long long pos);
int main(void)
{
    unsigned long long n,a,b,i;
    bsieve();
    scanf("%llu %llu",&a,&b);
    segmenthandle(a,b);
    return 0;
}
void bsieve()
{
    long long i,j;

    var[0/32]=setnotprime(var[0/32],0%32);
    var[1/32]=setnotprime(var[1/32],1%32);

    for(i=3;i<=N;i++)
        if(!checkprime(var[i/32],i%32))
            for(j=i*i;j<=N;j+=2*i)
                var[j/32]=setnotprime(var[j/32],j%32);

    primes[k++]=2;
    for(i=3;i<=N;i+=2)
        if(!checkprime(var[i/32],i%32))
                primes[k++]=i;
}

long long setnotprime(long long n,long long pos)
{
    return n|(1<<pos);
}

bool checkprime(long long n,long long pos)
{
    return (bool)(n&(1<<pos));
}

void segmenthandle(unsigned long long a,unsigned long long b)
{
    long long i,j,sqrtn;
    long long phi[b-a+1],n[b-a+1];
    for(i=0;i<=b-a;i++)
        phi[i]=n[i]=i+a;
    for(i=0;i<k;i++)
    {
        j=primes[i];
        if(primes[i]<a)
            j=((long long)ceil((double)a/(double)primes[i]))*primes[i];
        for(;j<=b;j+=primes[i])
        {
            while(n[j-a]%primes[i]==0)
                n[j-a]/=primes[i];
            phi[j-a]/=primes[i];
            phi[j-a]*=(primes[i]-1);
        }
    }
    for(i=0;i<=b-a;i++)
        if(n[i]!=1)
        {
            phi[i]/=n[i];
            phi[i]*=(n[i]-1);
        }
    for(i=0;i<=b-a;i++)
        printf("%lld\n",phi[i]);
}
