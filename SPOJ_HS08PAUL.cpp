#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define N 10000000

using namespace std;

int var[(N>>5)+1], primes[N];

void bsieve();
bool checkprime(int n,int pos);
int setnotprime(int n,int pos);

int main(void)
{
    bsieve();

    long long i, j, t, n, lo, hi, mid, out, l;
    vector <long long> ans;

    for(i = 1; i*i <= 10000000; i++)
        for(j = 1; j*j*j*j <= 10000000; j++)
        {
            if(i*i+j*j*j*j > 2 && !((i*i+j*j*j*j)&1))
                continue;
            else if(!checkprime(var[(i*i + j*j*j*j)>>5],(i*i + j*j*j*j)&31))
                ans.push_back(i*i+j*j*j*j);
        }

    sort(ans.begin(), ans.end());
    unique(ans.begin(), ans.end());
    l = ans.size()-1;

    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld", &n);
        lo = out = 0;
        hi = l;

        while(lo <= hi)
        {
            mid = (lo + hi) >> 1;
            if(ans[mid] <= n)
            {
                out = mid+1;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }

        printf("%lld\n", out);
    }

    return 0;
}

void bsieve()
{
    long long i,j;

    ///Setting all multiples of any number as not prime.
    ///Except 2 all even numbers are not prime
    for(i=3; i<=N; i++)
        if(!checkprime(var[i>>5],i&31))
            for(j=i*i; j<=N; j+=2*i)
                var[j>>5]=setnotprime(var[j>>5],j&31);
}

int setnotprime(int n,int pos)
{
    return n|(1<<pos);
}

bool checkprime(int n,int pos)
{
    return (bool)(n&(1<<pos));
}
