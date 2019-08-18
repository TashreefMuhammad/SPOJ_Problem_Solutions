#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t,n,i,x,y,x1,y1,x2,y2,xo1,xo2,yo1,yo2;
    char o;
    //scanf("%d",&t);
    cin>>t;
    while(t--)
    {
        xo1=yo1=2000;
        xo2=yo2=-2000;
        //scanf("%d",&n);
        cin>>n;
        while(n--)
        {
            //fflush(stdin);
            //scanf("%c",&o);
            cin>>o;
            if(o=='p')
            {
                scanf("%d%d",&x,&y);
                if(xo1>x)
                    xo1=x;
                if(xo2<x)
                    xo2=x;
                if(yo1>y)
                    yo1=y;
                if(yo2<y)
                    yo2=y;
            }
            else if(o=='c')
            {
                scanf("%d%d%d",&x,&y,&x1);
                if(xo1>x-x1)
                    xo1=x-x1;
                if(xo2<x+x1)
                    xo2=x+x1;
                if(yo1>y-x1)
                    yo1=y-x1;
                if(yo2<y+x1)
                    yo2=y+x1;
            }
            else if(o=='l')
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                if(x1>x2)
                {
                    if(xo1>x2)
                        xo1=x2;
                    if(xo2<x1)
                        xo2=x1;
                }
                else
                {
                    if(xo1>x1)
                        xo1=x1;
                    if(xo2<x2)
                        xo2=x2;
                }
                if(y1>y2)
                {
                    if(yo1>y2)
                        yo1=y2;
                    if(yo2<y1)
                        yo2=y1;
                }
                else
                {
                    if(yo1>y1)
                        yo1=y1;
                    if(yo2<y2)
                        yo2=y2;
                }
            }
        }
        printf("%d %d %d %d\n",xo1,yo1,xo2,yo2);
    }
    return 0;
}
