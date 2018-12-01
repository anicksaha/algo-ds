#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

/* this function calculates (a*b)%c taking into account that a*b might overflow */
ll mulmod(ll a,ll b,ll c)
{
    ll x = 0,y=a;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y);
            x%=1000000007;
        }
        y = (y*2);
        y%=1000000007;
        b /= 2;
    }
    return x%c;
}

/* This function calculates (a^b)%c */
ll modulo(ll a,ll b,ll c)
{
    ll x=1,y=a;

    while(b > 0)
    {
    	if(b%2 == 1)
            //x=(x*y)%c;
            x=mulmod(x,y,c);

        //y = (y*y)%c;
        y=mulmod(y,y,c);
        b /= 2;
	}
 	return x%c;
}


ll modInverse(ll a,ll m)
{
    return modulo(a,m-2,m);
}

// modInverse Ends here

vector<int> adj[100001];
ll component_size;
bool visited[100001];

void getsize(int node)
{
    component_size++;
    visited[node]=1;
    for(int i=0;i<adj[node].size();i++)
        if(!visited[adj[node][i]])
            getsize(adj[node][i]);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,tmp;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            adj[i].clear(),visited[i]=false;

        for(int i=1;i<=n;i++)
        {
             scanf("%d",&tmp);
             adj[i].push_back(tmp);
             adj[tmp].push_back(i);
        }

        vector<ll> ans;

        for(int i=1;i<=n;i++)
            if(!visited[i])
            {
                component_size=0;
                getsize(i);
                ans.push_back(component_size);
            }

        map<ll,ll> max_prime_powers;

        for(ll i=0;i<ans.size();i++)
        {
            for(ll j=2;j<=ans[i];j++)
            {
                ll temp=0;
                while(ans[i]%j==0)
                    temp++,ans[i]/=j;
                max_prime_powers[j]=max(max_prime_powers[j],temp);
            }
            //if(ans[i]>1){}
                //max_prime_powers[ans[i]]=max(max_prime_powers[ans[i]],temp);
        }

        ll lcm=1;
        ll foo;
        map<ll,ll> :: iterator  it;

        for(it=max_prime_powers.begin();it!=max_prime_powers.end();it++)
        {
            //cout<<it->first<<" "<<it->second<<endl;
            foo=modulo(it->first,it->second,1000000007);
            //cout<<foo<<endl;
            lcm*=foo;
            //cout<<lcm<<endl;
            lcm%=1000000007;
        }

        cout<<lcm<<endl;
    }
	return 0;
}
