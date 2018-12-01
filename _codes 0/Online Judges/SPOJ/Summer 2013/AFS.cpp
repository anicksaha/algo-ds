#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<cstring>

using namespace std;
typedef unsigned long long int ll;

ll ans[1000010];

int main()
{
    ans[0]=ans[1]=0;
    for(ll i=2;2*i<(1000010); i++)
            for(ll j=2*i; j<1000010; j=j+i)
                ans[j]+=i;

    for(int i=2;i<1000001;i++)
        ans[i]=ans[i]+ans[i-1]+1;


    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }

}

