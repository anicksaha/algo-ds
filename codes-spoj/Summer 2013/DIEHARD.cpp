#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int dp[1100][1100] ;

int recurse( int h , int a , int cnt , bool flag )
{

    if ( h <= 0 || a <= 0 )
        return cnt ;

    if(dp[h][a])
        return dp[h][a] ;

    if(flag)
        dp[h][a] = max( dp[h][a],recurse( h + 3 , a + 2 , cnt + 1 , !flag ) ) ;
    else
        dp[h][a] = max ( dp[h][a], max (recurse( h - 5 , a - 10 , cnt + 1 , !flag ), recurse ( h - 20 , a + 5 , cnt + 1 , !flag ) )  ) ;

    return dp[h][a];
}

int main()
  {
    int t , a , b ;
    cin>>t;


    while(t--)
    {
     memset ( dp , 0 , sizeof dp ) ;
     scanf("%d%d", &a , &b );
     printf("%d\n" , recurse( a , b , -1 ,  1 ));
    }

  }
