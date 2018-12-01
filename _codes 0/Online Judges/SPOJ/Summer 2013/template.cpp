/*
    anick saha
*/

#include<sstream>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<functional>
#include<numeric>
#include<bitset>
#include<utility>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<iterator>
#include<ctime>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;

#define SL(x) scanf("%lld",&x)
#define SLL(x) scanf("%llu",&x)
#define S(x) scanf("%d",&x)
#define SS(x) scanf("%s",s)
#define P(x) printf("%d",x)
#define PL(x) printf("%lld",x)
#define PLL(x) printf("%llu",x)
#define FOR(p,q,r) for(int p=q;p<=r;p++)
#define REV(p,q,r) for(int p=q;p>=r;p--)
#define W(x) while(x--)
#define TC int t;for(scanf("%d",&t);t>0;t--)
#define NL printf("\n")

#define M 1000000007

ll gcd(ll a,ll b)
{
    return ( a%b != 0 ? gcd(b,a%b) : b );
}

ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}

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

bitset<1000010> isprime;

void gen()
{
    isprime[0]=isprime[1]=true;
    for(ll i=2; i*i<1000010 ; i++)
        if(!isprime[i])
            for(ll j=i*i; j<1000010; j=j+i)
                isprime[j]=true;
}

vector<int> primes;

int main()
{

	//freopen("C:\\Users\\Anick\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\Anick\\Desktop\\out.txt","w",stdout);

	return 0;

}

