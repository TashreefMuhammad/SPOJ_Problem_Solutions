#include <stdio.h>
#include <math.h>

int main(void)
{
    int q,in1,in2,row,i,j,x,y,lim,n;
    scanf("%d",&n);

    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    row = floor(log2(n)) + 1;
    int st[row][n];

    for(i=0; i<n; i++)
        st[0][i]=i;
    for(i=1; i<row; i++)
    {
        lim=n-(1<<i)+1;
        for(j=0; j<lim; j++)
        {
            x = st[i-1][j];
            y = st[i-1][j+(1<<i-1)];
            st[i][j] = arr[x]<arr[y]?x:y;
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&in1,&in2);
        n = log2(in2-in1);
        x = st[n][in1];
        y = st[n][in2-(1<<n)+1];
        printf("%d\n",arr[arr[x]<arr[y]?x:y]);
    }
    return 0;
}
