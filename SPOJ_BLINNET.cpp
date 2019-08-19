#include <bits/stdc++.h>

using namespace std;

typedef struct grp grp;

struct grp
{
    int from,to,weight;
};

bool comp(grp g1,grp g2)
{
    return g1.weight < g2.weight;
}

int parent[10001];

int find_parent(int node);

int main(void)
{
    int t,i,n,e,u,v,cost,j,m;
    string s;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        grp temp;
        vector <grp> ar;
        for(i=0; i<n; i++)
        {
            parent[i]=i;
            cin>>s>>m;
            while(m--)
            {
                scanf("%d %d",&temp.to,&temp.weight);
                temp.from=i;
                temp.to--;
                ar.push_back(temp);
            }
        }
        e=ar.size();
        sort(ar.begin(),ar.end(),comp);
        cost=0;
        for(i=0; i<e; i++)
        {
            u=find_parent(ar[i].from);
            v=find_parent(ar[i].to);
            if(u!=v)
            {
                parent[v]=u;
                cost+=ar[i].weight;
            }

        }

        printf("%d\n",cost);
    }

    return 0;
}
int find_parent(int node)
{
    if(parent[node]==node)
        return node;
    else
        return parent[node]=find_parent(parent[node]);
}
