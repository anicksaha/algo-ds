#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>

using namespace std;
typedef int ll;

ll gcd(ll a,ll b)
{
    return ( a%b != 0 ? gcd(b,a%b) : b );
}

bitset<1000010> isprime;
void gen()
{
    isprime[0]=isprime[1]=false;
    for(ll i=2; i*i<1000010 ; i++)
        if(isprime[i])
            for(ll j=i*i; j<1000010; j=j+i)
                isprime[j]=false;
}
vector<int> primes;

void prime_store()
{
    for(ll i=2;i<1000001;i++)
        if(isprime[i])
            primes.push_back(i);
}

ll numfac(ll n)
{
    if(n==0)return 0;
    if(n==1)return 1;
    int i, j;
    ll count=0,ret=1;
    j = sqrt(n);

    for(i=0; i<primes.size() && primes[i]<= j ; i++)
    {
        count=0;
        while(n%primes[i]==0)
        {
            count++;
            n/=primes[i];
        }
        ret*=count+1;
    }

    if(n!=1)ret*=2;
    return ret;
}

int main()
{
    isprime.set();
    gen();
    prime_store();
    int t,a,b,g;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        g=gcd(a, b);
        printf("%d\n",numfac(g));
    }
    return 0;
}
