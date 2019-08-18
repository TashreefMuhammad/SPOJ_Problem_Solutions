#include <stdio.h>
#define N 100000000

int var[N+1];
int primes[N];
int k;

void bit_sieve();
bool checkprime(int n,int pos);
int setnotprime(int n,int pos);

int main(void)
{
    bit_sieve();
    for(int i=0; i<k; i+=100)
        printf("%d\n",primes[i]);
    return 0;
}

void bit_sieve()
{
    int i,j;
    var[0/32]=setnotprime(var[0/32],0%32);
    var[1/32]=setnotprime(var[1/32],1%32);
    for(i=4; i<=N; i+=2)
        var[i/32]=setnotprime(var[i/32],i%32);
    for(i=3; i*i<=N; i+=2)
        if(!checkprime(var[i/32],i%32))
            for(j=i*i; j<=N; j+=2*i)
                var[j/32]=setnotprime(var[j/32],j%32);
    primes[k++]=2;
    for(i=3; i<=N; i++)
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
