#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct mystruct mystruct;
struct mystruct
{
    long pos,fuel;
};
bool comp(mystruct v1,mystruct v2)
{
    return v1.pos<v2.pos;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long t,n,l,p,i,stops;
    cin>>t;
    while(t--)
    {
        stops=0;
        cin>>n;
        mystruct ar[n];
        for(i=0;i<n;i++)
            cin>>ar[i].pos>>ar[i].fuel;
        cin>>l>>p;
        if(p>=l)
            cout<<"0\n";
        else
        {
            for(i=0;i<n;i++)
                ar[i].pos=l-ar[i].pos;
            sort(ar,ar+n,comp);
            priority_queue <long> q;
            for(i=0;i<n && ar[i].pos<=p;q.push(ar[i++].fuel),ar[i-1].fuel=0);
            while(!q.empty())
            {
                p+=q.top();
                q.pop();
                stops++;
                if(p>=l)
                    break;
                for(i=0;i<n && ar[i].pos<=p;i++)
                    if(ar[i].fuel!=0)
                    {
                        q.push(ar[i].fuel);
                        ar[i].fuel=0;
                    }
            }
            if(p>=l)
                cout<<stops<<"\n";
            else
                cout<<"-1\n";
        }
    }
    return 0;
}
