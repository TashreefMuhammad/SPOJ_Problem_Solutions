#include <stdio.h>
#include <math.h>
#define N 1000
using namespace std;
int var[N+1];
int primes[N];
int k;

void eulerPHI(unsigned long long n);
void bsieve();
bool checkprime(int n,int pos);
int setnotprime(int n,int pos);
int main(void)
{
    unsigned long long n,t;
    bsieve();
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu",&n);
        eulerPHI(n);
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

int setnotprime(int n,int pos)
{
    return n|(1<<pos);
}

bool checkprime(int n,int pos)
{
    return (bool)(n&(1<<pos));
}

void eulerPHI(unsigned long long n)
{
    int i,sqrtn=sqrt(n);
    unsigned long long res=n,st=n;

    for(i=0;i<k && primes[i]<=sqrtn;i++)
    {
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
                n/=primes[i];
            sqrtn=sqrt(n);
            res/=primes[i];
            res*=primes[i]-1;
        }
    }

    if(n!=1)
    {
        res/=n;
        res*=n-1;
    }
    printf("%llu\n",res);
}
