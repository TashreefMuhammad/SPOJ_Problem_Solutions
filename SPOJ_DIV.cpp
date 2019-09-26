#include <stdio.h>
#include <math.h>
#define N 1000

int j, k, var[(N>>5)+1], primes[N];

void decomp(int n);
void bsieve();
bool checkprime(int n,int pos);
int setnotprime(int n,int pos);

int main(void)
{
    int n,i;
    bsieve();
    for(i=9,j=0; i<=1000000; i++)
        decomp(i);

    return 0;
}

void bsieve()
{
    int i,j;

    for(i=3; i<=N; i++)
        if(!checkprime(var[i>>5],i&31))
            for(j=i*i; j<=N; j+=2*i)
                var[j>>5]=setnotprime(var[j>>5],j&31);

    primes[k++]=2;
    for(i=3; i<=N; i+=2)
        if(!checkprime(var[i>>5],i&31))
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

void decomp(int n)
{
    int i,cnt,nk,sqrtn=sqrt(n),divisor=1,st=n;
    for(i=0; i<k && primes[i]<=sqrtn; i++)
    {
        if(n&1 && n<1000 && !checkprime(var[n>>5],n&31))
            break;
        if(n%primes[i]==0)
        {
            cnt=0;
            while(n%primes[i]==0)
            {
                cnt++;
                n/=primes[i];
            }
            divisor*=(cnt+1);
            sqrtn=sqrt(n);
        }
    }
    if(n!=1)
        divisor*=2;
    for(i=0; i<k && primes[i]*primes[i]<=divisor; i++)
    {
        if(divisor%primes[i]==0)
        {
            n=divisor/primes[i];
            if(n&1 && n>2 && !checkprime(var[n>>5],n&31) && n!=primes[i])
            {
                if(++j%9==0)
                    printf("%d\n",st);
                break;
            }
        }
    }
}
