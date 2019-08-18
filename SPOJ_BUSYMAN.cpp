#include <bits/stdc++.h>
using namespace std;
struct routine{
long st,et;
}c[1000000];
bool cmp(routine a,routine b)
    {
        if(a.et==b.et)
            return a.st<b.st;
        else
            return a.et<b.et;
    }

int main(void)
{
    long t,i,n,j,ans,prev;
    cin>>t;
    int fin[t];
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
            cin>>c[j].st>>c[j].et;
        sort(c,c+n,cmp);
        ans=0;
        prev=-1;
        for(j=0;j<n;j++)
            if(c[j].st>=prev)
            {
                ans++;
                prev=c[j].et;
            }
        fin[i]=ans;
    }
    for(i=0;i<t;i++)
        cout<<fin[i]<<endl;
    return 0;
}
