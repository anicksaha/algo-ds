#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>

using namespace std;

pair<int,int> a[100010];


bool nick(pair<int,int> x, pair<int,int> y)
{
    if(x.first<y.first)
        return true;

    return false;
}
// true if we don't wanna swap

bool mysort(pair<int,int> x, pair<int,int> y)
{
    if(x.first > y.first)
        return false;
    if(x.first==y.first)
    {
        if(x.second < y.second)
            return false;
    }

    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i]=make_pair(x,y);
        }

        //sort(&a[1],&a[n+1],nick);
        //reverse(&a[1],&a[n+1]);
        /*
        for(int i=1;i<=n;i++)
            cout<<a[i].first<<endl;
        */

        sort(&a[1],&a[n+1],mysort);

        double dist = 0.0000;

        for(int i=2;i<=n;i++)
        {
            dist+= sqrt( (a[i].first-a[i-1].first)*(a[i].first-a[i-1].first) + (a[i].second-a[i-1].second)*(a[i].second-a[i-1].second));
        }

        printf("%0.2lf\n", dist);
    }

    return 0;
}
