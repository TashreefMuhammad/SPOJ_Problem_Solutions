#include <bits/stdc++.h>
int main(void)
{
    int i,n,k,s,sum=0;
    scanf("%d %d %d",&n,&k,&s);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    std::sort(a,a+n,std::greater<int>());
    for(i=0;sum<k*s;i++)
        sum+=a[i];
    printf("%d",i);
    return 0;
}
