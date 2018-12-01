#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int a[8][8][8][8];

int abs(int x)
{
    if(x>=0)return x;
    else return -1*x;
}

bool isp(int x,int y,int x1,int y1)
{
    if( (abs(x-x1)==1&&abs(y-y1)==2)||(abs(x-x1)==2&&abs(y-y1)==1) )
        return true;
    return false;
}

int main()
{
    int x1,x2,y1,y2,x,y;

    for(x1=0;x1<=7;x1++)
        for(y1=0;y1<=7;y1++)
            for(x2=0;x2<=7;x2++)
                for(y2=0;y2<=7;y2++)
                    a[x1][y1][x2][y2]=INT_MAX;

    for(x1=0;x1<=7;x1++)
        for(y1=0;y1<=7;y1++)
            {
                for(x2=0;x2<=7;x2++)
                    for(y2=0;y2<=7;y2++)
                        if(isp(x1,y1,x2,y2))
                            a[x1][y1][x2][y2]=(x1*x2)+(y1*y2);

                a[x1][y1][x1][y1]=0;
            }




    for(x=0;x<=7;x++)
    for(y=0;y<=7;y++)
    for(x1=0;x1<=7;x1++)
    for(y1=0;y1<=7;y1++)
    for(x2=0;x2<=7;x2++)
    for(y2=0;y2<=7;y2++)
        if(a[x1][y1][x][y]!=INT_MAX && a[x][y][x2][y2]!=INT_MAX)
                    a[x1][y1][x2][y2]=min(a[x1][y1][x2][y2],a[x1][y1][x][y]+a[x][y][x2][y2]);



    int b,c,d,e;
    while(cin>>b>>c>>d>>e)
    {
        if(a[b][c][d][e]!=INT_MAX)
    printf("%d\n",a[b][c][d][e]);
    else
    printf("-1\n");
    }
    return 0;
}

