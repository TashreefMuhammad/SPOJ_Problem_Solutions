#include <bits/stdc++.h>

using namespace std;

stack <long> st;
vector <char> col;
bool f;

void DFS(int num,vector <long> grp[]);

int main(void)
{
    long n,m,i,u,v,c;
    scanf("%ld %ld",&n,&m);
    vector <long> grp[n];
    for(i=0;i<n;i++)
        col.push_back('W');
    for(i=0;i<m;i++)
    {
        scanf("%ld %ld",&u,&c);
        while(c--)
        {
            scanf("%ld",&v);
            grp[v-1].push_back(u-1);
        }
    }
    for(i=0;i<n;i++)
        sort(grp[i].begin(),grp[i].end(),greater <int> ());
    for(i=n-1;i>=0 && f==false;i--)
        if(col[i]=='W')
            DFS(i,grp);
    if(f==true)
        printf("Sandro fails.");
    else
    {
        while(!st.empty())
        {
            printf("%ld ",st.top()+1);
            st.pop();
        }
    }
    return 0;
}
void DFS(int num,vector <long> grp[])
{
    col[num]='G';
    int i,l=grp[num].size();
    for(i=0;i<l && f==false;i++)
    {
        if(col[grp[num][i]]=='W')
            DFS(grp[num][i],grp);
        else if(col[grp[num][i]]=='G')
        {
            f=true;
            break;
        }
    }
    col[num]='B';
    st.push(num);
}
