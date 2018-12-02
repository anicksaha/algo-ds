#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<cstring>

using namespace std;
typedef unsigned long long int ll;

ll ans[10000001];
bool isprime[10000001];

void gen()
{
    isprime[0]=isprime[1]=false;

    for(ll i=2; i<10000001 ; i++)
        if(isprime[i])
        {
            ans[i]=i;
            for(ll j=i*i; j<10000001; j=j+i)
            {
               isprime[j]=false;
               //if(j==12)cout<<"YO<"<< i<<endl;
               if(!ans[j])
               ans[j]=i;
            }
        }

}

int main()
{
    //freopen("C:\\Users\\Anick\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\Anick\\Desktop\\out.txt","w",stdout);

    memset(ans, 0, sizeof(ans));
    memset(isprime, true, sizeof(isprime));
    gen();

    for(int i=1;i<10000001;i++)
        ans[i]+=ans[i-1];


    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }

}
