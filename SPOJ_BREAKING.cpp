#include <stdio.h>
#include <math.h>
#define N 1000000

int var[N+1],p[N+1],e[N+1];
int primes[N];
int k,nk;

void decomp(int n);
void bsieve(int n);
bool checkprime(int n,int pos);
int setnotprime(int n,int pos);

int main(void)
{
    int i,n,j,t;
    bsieve(N);
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        scanf("%d",&n);
        decomp(n);
        printf("Case %d:",j+1);
        for(i=0;i<nk;i++)
            printf(" %d",p[i]);
        printf("\n");
        nk=0;
    }

    return 0;
}
void bsieve(int n)
{
    int i,j;

    var[0/32]=setnotprime(var[0/32],0%32);
    var[1/32]=setnotprime(var[1/32],1%32);

    for(i=4;i<=n;i+=2)
        var[i/32]=setnotprime(var[i/32],i%32);

    for(i=3;i*i*i*i<=n;i+=2)
        if(!checkprime(var[i/32],i%32))
            for(j=i*i;j*j<=n;j+=2*i*i)
                var[j/32]=setnotprime(var[j/32],j%32);

    primes[k++]=2;
    for(i=3;i*i<=n;i++)
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

void decomp(int n)
{
    int i,cnt,sqrtn=sqrt(n);

    for(i=0;i<k && primes[i]<=sqrtn;i++)
    {
        if(n%primes[i]==0)
        {
            cnt=0;
            while(n%primes[i]==0)
            {
                cnt++;
                n/=primes[i];
            }
            if(cnt>0)
            {
                p[nk]=primes[i];
                e[nk]=cnt;
                nk++;
            }
        }
    }

    if(n!=1)
    {
        p[nk]=n;
        e[nk]=1;
        nk++;
    }
}
