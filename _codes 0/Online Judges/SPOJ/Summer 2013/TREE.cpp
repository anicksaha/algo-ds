#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<fstream>

using namespace std;

typedef unsigned long long ll;

#define M 1000000007

ll meh(ll a,ll b,ll c)
{
	ll x=1,y=a;

    while(b > 0)
    {
    	if(b%2 == 1)
            x=(x*y)%c;

        y = (y*y)%c;
        b /= 2;
	}
 	return x%c;
}

// (n^(n-2)) * ((n-1)^(n*(k-1))) * (k^(n*k-2))

int main()
{

    ll n,k;
    cin>>n>>k;
    ll a,b,c,d,e;
    ll p,q,r,ans;

    if(n==1)
    {
        if(k==1)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }

    else if(k==1)
    {
        ans=meh(n,n-2,M);
        cout<<ans<<endl;   // No. of spanning trees on 'N' labelled nodes = N^(N-2)
    }

    else
    {
        a=meh(n,n-2,M);
        b=(n*(k-1))%M;
        c=meh(n-1,b,M);
        d=(n*k);
        d-=2;
        e=meh(k,d,M);

        p=a*c;
        p%=M;
        q=p*e;
        q%=M;

        ans=q;
        cout<<ans<<endl;
    }

    return 0;
}
