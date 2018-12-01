#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll row_sum[1001];
ll col_sum[1001];
ll row_accumulation[1000001];
ll col_accumulation[1000001];
priority_queue<ll> row,col;

int main()
{
    ll n,m,k,p;
    cin>>n>>m>>k>>p;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            ll foo;
            cin>>foo;
            row_sum[i]+=foo;
            col_sum[j]+=foo;
        }


    for(int i=1;i<=n;i++)
        row.push(row_sum[i]);

    for(int i=1;i<=m;i++)
       col.push(col_sum[i]);


    ll R,C;

    for(int i=1;i<=k;i++)
    {
        R=row.top();
        row.pop();

        C=col.top();
        col.pop();

        row_accumulation[i]=row_accumulation[i-1]+R;
        col_accumulation[i]=col_accumulation[i-1]+C;


        R-=(p*m);
        C-=(p*n);
        row.push(R);
        col.push(C);
    }

    ll ans=LLONG_MIN;

    for(int i=0;i<=k;i++)  // Number of times we r picking a row.
       ans=max( ans, row_accumulation[i] + col_accumulation[k-i] -(k-i)*i*p);

    cout<<ans<<endl;

    return 0;
}
