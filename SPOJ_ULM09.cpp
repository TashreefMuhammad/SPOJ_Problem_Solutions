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
    int u,v,m,tot_cost,cost;
    long i,n;
    while(1)
    {
        tot_cost=0;
        scanf("%d%ld",&m,&n);
        if(m==0 && n==0)
            break;
        grp temp;
        vector <grp> ar;
        for(i=0; i<m; i++)
            parent[i]=i;
        for(i=0; i<n; i++)
        {
            scanf("%d %d %d",&temp.from,&temp.to,&temp.weight);
            tot_cost+=temp.weight;
            ar.push_back(temp);
        }
        sort(ar.begin(),ar.end(),comp);
        cost=0;
        for(i=0; i<n; i++)
        {
            u=find_parent(ar[i].from);
            v=find_parent(ar[i].to);
            if(u!=v)
            {
                parent[v]=u;
                cost+=ar[i].weight;
            }

        }

        printf("%d\n",tot_cost-cost);
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
