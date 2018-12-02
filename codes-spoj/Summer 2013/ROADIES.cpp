#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b
int main()
{
    int t;
    int  price[10005];
    int i,j,l;
    cin>>t;

    while(t--)
    {
        cin>>l;
        price[0]=0;
        for(i=1;i<=l;i++)
        {
        cin>>price[i];

        }

        long long int dp[l+1];
        dp[0]=0;

        for(i=1;i<=l;i++)
        dp[i]=price[i];


        for(i=1;i<=l;i++)
        {
            for(j=1;j<i;j++)
            {
                dp[i]=max(dp[i], dp[j]+dp[i-j]);

            }

         }

         cout<<dp[l]<<endl;
    }
return 0;
}
