#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int m,n;
int area(int a[]);

int main(void)
{
    int i,j,t,k,maximum;
    char c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        int mat[m][n];
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>c;
                if(c=='R')
                    mat[i][j]=0;
                else
                    mat[i][j]=1;
            }
        }
        maximum=area(mat[0]);

        for(i=1;i<m;i++)
        {
            for(j=0;j<n;j++)
                if(mat[i][j])
                    mat[i][j]+=mat[i-1][j];
            maximum=max(maximum,area(mat[i]));
        }
        printf("%d\n",3*maximum);
    }

    return 0;
}
int area(int a[])
{
    stack <int> st;
    int i,top,temp,maximum=0;
    for(i=0;i<n;)
    {
        if(st.empty()||a[st.top()]<=a[i])
            st.push(i++);
        else
        {
            top=st.top();
            st.pop();
            temp=a[top];
            if(st.empty())
                temp*=i;
            else
                temp*=(i-st.top()-1);
            if(temp>maximum)
                maximum=temp;
        }
    }
    while(!st.empty())
    {
        top=st.top();
        st.pop();
        temp=a[top];
        if(st.empty())
            temp*=i;
        else
            temp*=i-st.top()-1;
        if(temp>maximum)
            maximum=temp;
    }
    return maximum;
}
