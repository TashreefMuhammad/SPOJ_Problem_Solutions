#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n,k,i,lo,hi,mid,c=0;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n-1;i++)
    {
        lo=i+1;
        hi=n-1;
        while(lo<=hi)
        {
            mid=(hi+lo)/2;
            if(a[mid]==a[i]+k)
                break;
            else if(a[mid]>a[i]+k)
                hi=mid-1;
            else
                lo=mid+1;
        }
        if(a[mid]==a[i]+k)
            c++;
    }
    cout<<c;
    return 0;
}
