#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int arr[100010];

int dp[100010]; // inc
int dp2[100010]; // dec

int main()
{

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);

    dp2[0]=INT_MIN;
    dp[0]=INT_MIN;
    dp[n+1]=INT_MIN;
    dp2[n+1]=INT_MIN;

    int ans=0;

    dp[n]=1;
    for(int i=n-1;i>=1;i--)
    {
        if(arr[i]<arr[i+1])
            dp[i]=dp[i+1]+1;
        else
            dp[i]=1;
    }

    dp2[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(arr[i]>arr[i-1])
            dp2[i]=dp2[i-1]+1;
        else
            dp2[i]=1;
    }

    /*
    for(int i=1;i<=n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<dp2[i]<<" ";
    cout<<endl;
    */


    for(int i=2;i<=n-1;i++)
    {
        if(arr[i+1]-arr[i-1]>1)
            ans=max(dp[i+1]+dp2[i-1],ans);
        ans=max(ans,dp[i+1]);
        ans=max(ans,dp2[i-1]);
    }
    ans=max(ans,dp[2]);
    ans=max(ans,dp2[n-1]);
    printf("%d",ans+1);

	return 0;
}
