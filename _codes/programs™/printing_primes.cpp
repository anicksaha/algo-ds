#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<vector>
#include<bitset>

using namespace std;
typedef long int ll;

bitset<100000001> isprime;

void gen()
{
    ll i,j;
    for(ll i=2; i*i<100000001 ; i++)
        if(isprime[i])
            for(ll j=2*i; j<100000001; j=j+i)
                isprime[j]=false;
}

vector<ll> foo;

int main()
{

    freopen("C:\\Users\\Anick\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\Anick\\Desktop\\out.txt","w",stdout);

    isprime.set();
    gen();
    //int n;
    //cin>>n;

    for(int i=2;i<=100000000;i++)
        if(isprime[i])
            foo.push_back(i);

    for(int i=0;i<foo.size()-1;i+=100)
        printf("%d,",foo[i]);


    return 0;
}
