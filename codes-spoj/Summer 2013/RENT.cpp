#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct data
{
    int st, en, pr;
} d[10009];

static int dp[2000009];

inline bool comp(data x, data y)
{
    if(x.en<= y.en)
        return true;
    return false;
}

int main()
{
    int t, i, k, n, mx;
    scanf("%d",&t);

    while(t--)
    {
        memset(dp, 0, sizeof dp);
        scanf("%d",&n);
        mx = 0;

        for(i = 0; i < n; i++)
        {
            scanf("%d%d%d",&d[i].st,&d[i].en,&d[i].pr);
            d[i].en += d[i].st;
            mx = max(mx, d[i].en);
        }

        sort(d, d + n, comp);  // sort according to end time

        for(i = k = 0; i < mx; i++)
        {
            while(k < n && d[k].st == i)
            {
                dp[d[k].en] = max(dp[d[k].st] + d[k].pr, dp[d[k].en]);
                k++;
            }

            dp[i + 1] = max(dp[i + 1], dp[i]);
        }

        printf("%d\n", dp[mx]);
    } // TC

    return 0;
}
