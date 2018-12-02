#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>

using namespace std;

typedef long long ll;
#define mm 1000000007

ll vec[310];
ll fact[310];
ll invfact[310];

void init()
{
    vec[1] = 1;
    for(int i=2; i<=301; i++)
        vec[i] = (-(mm/i) * vec[mm % i]) % mm + mm;

    invfact[0]=1;
    invfact[1]=1;

    for(int i=2; i<=301; i++)
        invfact[i]=(invfact[i-1]*vec[i])%mm;

    fact[0]=1;
    fact[1]=1;

    for(int i=2; i<=301; i++)
        fact[i]=(fact[i-1]*i)%mm;

}


int main()
{
    init();
    ll n, w, t, r,foo,bar;
    cin>>n>>w>>t>>r;

    foo=(fact[n]*invfact[w])%mm;
    foo*=invfact[t];
    foo%=mm;
    foo*=invfact[r];
    foo%=mm;

    cout<<foo<<endl;


}
