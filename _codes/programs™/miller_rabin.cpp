#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<fstream>

using namespace std;
typedef unsigned long long ll;


/* this function calculates (a*b)%c taking into account that a*b might overflow */
ll mulmod(ll a,ll b,ll c)
{
    ll x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
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



/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(ll p,int iteration){
    if(p==1 || p==0 || p<0){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    ll s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        ll a=rand()%(p-1)+1,temp=s;
        ll mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        //cin>>n;
        while(!Miller(n,2))
            n--;

        printf("%lld\n",n);
        //cout<<n<<endl;
    }

    return 0;
}
