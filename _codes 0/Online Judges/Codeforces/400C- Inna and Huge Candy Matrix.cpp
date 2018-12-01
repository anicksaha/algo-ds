#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x,y;
};
int main()
{
    int n,m,x,y,z,p,nx,ny;

    cin>>n>>m>>x>>y>>z>>p;

    node points[p+1];


    for(int i=1;i<=p;i++)
    {
        cin>>points[i].x>>points[i].y;
    }

    x%=4;
    y%=2;
    z%=4;


    for(int i=1;i<=x;i++)
    {
        swap(m,n);

        for(int j=1;j<=p;j++)
        {
            nx=points[j].y;
            ny=m-points[j].x + 1;

            points[j].x=nx;
            points[j].y=ny;
        }
        //cout<<points[1].x<<" "<<points[1].y<<endl;
    }

    for(int i=1;i<=y;i++)
    {

        for(int j=1;j<=p;j++)
        {
            ny=m-points[j].y + 1;
            points[j].y=ny;
        }
        //cout<<points[1].x<<" "<<points[1].y<<endl;
    }

    for(int i=1;i<=z;i++)
    {
        swap(m,n);

        for(int j=1;j<=p;j++)
        {
            nx=n-points[j].y + 1;
            ny=points[j].x;

            points[j].x=nx;
            points[j].y=ny;
        }
        //cout<<points[1].x<<" "<<points[1].y<<endl;
    }

    // Print
    for(int i=1;i<=p;i++)
    {
        cout<<points[i].x<<" "<<points[i].y<<endl;
    }

    return 0;
}

