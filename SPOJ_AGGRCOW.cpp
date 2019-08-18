#include <stdio.h>
#include <algorithm>

using namespace std;

bool cover(int val,int n,int c,int a[]);

int main(void)
{
    int t,n,c,i,lo,hi,mid,out;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&c);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        lo=0;
        hi=a[n-1];
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            if(cover(mid,n,c,a))
            {
                out=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        printf("%d\n",out);
    }

    return 0;
}

bool cover(int val,int n,int c,int a[])
{
    int i,j=0;
    c--;
    for(i=1;i<n;i++)
    {
        if(a[i]-a[j]>=val)
        {
            c--;
            j=i;
        }
        if(c==0)
            break;
    }
    if(c<=0)
        return true;
    else
        return false;
}
