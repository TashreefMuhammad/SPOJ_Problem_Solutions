#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int t,i,l,sum;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        sum=0;
        l=s.size();
        for(i=0;i<l;i++)
            sum+=s[i]-'0';
        printf("%d\n",sum);
    }
    return 0;
}
