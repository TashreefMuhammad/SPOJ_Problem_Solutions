#include <stdio.h>
#include <math.h>
#define N 100000

long long var[N/32+1];
long long primes[N/10];
long long k;

void segmenthandle(unsigned long long a,unsigned long long b);
void bsieve();
bool checkprime(long long n,long long pos);
long long setnotprime(long long n,long long pos);
int main(void)
{
    unsigned long long n,a,b,i,t;
    bsieve();
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu %llu",&a,&b);
        segmenthandle(a,b);
    }
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
    long long i,j;
    bool check[b-a+1];

    for(i=0;i<=b-a;i++)
        check[i]=true;

    for(i=a;i<=b;i++)
    {
        for(j=0;j<k && primes[j]*primes[j]<=i;j++)
        {
            if(i%primes[j]==0 && i/primes[j]>1)
            {
                check[i-a] = false;
                break;
            }
        }
        if(check[i-a]==true && i!=1)
            printf("%lld\n",i);
    }
    printf("\n");

}
