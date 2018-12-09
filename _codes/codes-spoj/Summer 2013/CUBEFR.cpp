#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<cstring>
#include<vector>

using namespace std;
typedef unsigned long long int ll;

bool ans[1000010];
vector<int> foo;

int main()
{
    memset(ans, true, sizeof(ans));
    ans[0]=false;
    for(ll i=2;i*i*i<(1000010); i++)
        if(ans[i])
            for(ll j=i*i*i; j<1000010; j=j+(i*i*i))
                ans[j]=false;

    foo.push_back(0);
    foo.push_back(1);

    for(int i=2;i<1000001;i++)
        if(ans[i])
            foo.push_back(i);



    //for(int i=1;i<=20;i++)
       // cout<<foo[i]<<" ";


    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;

        cout<<"Case "<<i<<": ";

        if(!ans[n])
        {
            cout<<"Not Cube Free"<<endl;
            continue;
        }

        else
        //cout<<find(foo.begin(), foo.end(),n)-foo.begin()<<endl;
        cout<<lower_bound(foo.begin(), foo.end(),n)-foo.begin()<<endl;

    }
}

