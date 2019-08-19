#include <iostream>
#include <math.h>

using namespace std;

typedef struct node noded;

struct node
{
    int max1,max2;
};

noded tree[4*100001];
void build(int a[], int node, int start, int finish);
void update(int a[],int node, int start, int finish, int idx, int val);
noded output(int node, int start, int finish, int l, int r);

int main(void)
{
    int n,q,i,a,b;
    char op;
    scanf("%d",&n);
    int ar[n];
    for(i=0; i<n; i++)
        scanf("%d",&ar[i]);
    build(ar,1,0,n-1);
    scanf("%d",&q);
    while(q--)
    {
        cin>>op>>a>>b;
        if(op=='U')
            update(ar,1,0,n-1,a-1,b);
        else
        {
            noded out;
            out=output(1,0,n-1,a-1,b-1);
            printf("%d\n",out.max1+out.max2);
        }
    }
    return 0;
}
void build(int a[], int node, int start, int finish)
{
    if (start == finish)
    {
        tree[node].max1 = a[start];
        tree[node].max2 = -INFINITY;
    }
    else
    {
        int mid = (start + finish) / 2;
        build(a, node*2, start, mid);
        build(a, node*2+1, mid+1, finish);
        tree[node].max1 = max(tree[node*2].max1,tree[node*2+1].max1);
        tree[node].max2 = max(tree[node*2].max2,max(tree[node*2+1].max2,min(tree[node*2].max1,tree[node*2+1].max1)));
    }
}

noded output(int node,int start,int finish,int l,int r)
{
    noded out,out1,out2;
    out.max1=out.max2=out1.max1=out1.max2=out2.max1=out2.max2=-INFINITY;
    if(r < start || finish < l)
        return out;
    else if(l <= start && finish <= r)
        return tree[node];
    else
    {
        int mid = (start + finish) / 2;
        out1=output(2*node, start, mid, l, r);
        out2=output(2*node+1, mid+1, finish, l, r);
        out.max1 = max(out1.max1,out2.max1);
        out.max2 = max(out1.max2,max(out2.max2,min(out1.max1,out2.max1)));
        return out;
    }
}

void update(int a[],int node, int start, int finish, int idx, int val)
{
    if(start == finish)
    {
        a[idx]= val;
        tree[node].max1= val;
        tree[node].max2 = -INFINITY;
    }
    else
    {
        int mid = (start + finish) / 2;
        if(start <= idx and idx <= mid)
            update(a,2*node, start, mid, idx, val);
        else
            update(a,2*node+1, mid+1, finish, idx, val);
        tree[node].max1 = max(tree[node*2].max1,tree[node*2+1].max1);
        tree[node].max2 = max(tree[node*2].max2,max(tree[node*2+1].max2,min(tree[node*2].max1,tree[node*2+1].max1)));
    }
}
