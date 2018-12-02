#include<bits/stdc++.h>
using namespace std;

int cap[10001];
int ass[10001];
int dp[2][10001];

// DP[i][m]  means taking the iTh Pilot whats the cost if at this stage there are 'm' more assistants .

int main()
{
    int p; // number of Pilots

    scanf("%d",&p);

    for(int i=0;i<p;i++)
        scanf("%d%d",&cap[i],&ass[i]);

    memset(dp,0,sizeof(dp));

    dp[0][1]=ass[0];

    for(int i=1;i<p;i++)
    {
        for(int m=0;m<=i+1;m++)
        {
            if(m==0)
                dp[1][m]=cap[i]+dp[0][m+1];
            else if(m==i+1)
                dp[1][m]=ass[i]+dp[0][m-1];
            else
                dp[1][m]=min(cap[i]+dp[0][m+1], ass[i]+dp[0][m-1]);
        }
        for(int k=0;k<=p;k++)
            dp[0][k]=dp[1][k];
    }

    printf("%d",dp[0][0]);
    return 0;
}
