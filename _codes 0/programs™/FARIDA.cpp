#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

long long  a[1005];
long long dp[1005] ;

long long gemini( int n )
{
    if(n<=0)
        return 0;
    if(dp[n])
        return dp[n] ;
    else
        dp[n]=max(a[n]+ gemini(n-2),gemini(n-1)) ;

    return dp[n];
}

int main()
  {
    int t;
    cin>>t;
    int c=1;

    while(t--)
    {

        memset( dp , 0 , sizeof dp ) ;
        memset(a,0, sizeof(a));

        int n;
        cin>>n;

        for(int i=1;i<=n;i++)
            cin>>a[i];

        dp[1]=a[1];
        dp[2]=max(a[1],a[2]);
        /*
        for(int i=3;i<=n;i++)
            dp[i]=max(dp[i-2]+a[i],dp[i-1]);
        */
        cout<<"Case "<<c<<": "<<gemini(n)<<endl;
        c++;
    }

    return 0;

}

