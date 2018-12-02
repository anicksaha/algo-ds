#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
typedef long long int ll;

bool isprime[MAX+10];
bool mapped_ans[MAX+10];

void sieve()
{
    memset(isprime,true,sizeof(isprime));
    ll i,j;
    isprime[0]=false;
    isprime[1]=false;

    for(i=2;i*i<=MAX ;i++)
        if(isprime[i])
        for(j=i*i;j<=MAX;j=j+i)
            isprime[j]=false;
}

int main()
{
    sieve();

    ll t,n,m,k,diff;
    cin>>t;

    while(t--)
    {
        cin>>m>>n;

        if(n<=100000)
        {
            for(ll i=m; i<=n; i++)
            {
                if(isprime[i])
                    cout<<i<<endl;
            }
        } // if within Range
        else
        {
            diff=n-m;

            memset(mapped_ans,true,sizeof(mapped_ans));

            for(ll i=2; i*i<=n;  i++)
            {
                if(isprime[i])
                {
                    k=m/i; // 125/2 = 62
                    k=k*i; // 124
                    if(k<m)
                        k=k+i; // 126

                    if(k==i)
                        k+=i;

                    for(;k<=n; k+=i)
                        mapped_ans[k-m]=false;
                }
            }

            // ANS Print
            for(ll i=0;i<=diff;i++)
            {
                if(mapped_ans[i])
                    cout<<i+m<<endl;
            }
        }
        cout<<endl;
	}
    return 0;
}
