#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int opt[2002];
int q[2002];
pair<int,pair<int,int> > foo[2002];

int gemini(int j)
{
    if(j==0) opt[j]=0;
    else if(opt[j]== -1)
    opt[j]= max( foo[j].second.second + gemini(q[j]), gemini(j-1));
    return opt[j];
}

int main()
{
    int a, b, c , i, j, ans;
    int t, n ;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>a>>b>>c;
            foo[i].first=b;
            foo[i].second= make_pair(a,c);
        }

        sort(&foo[1],&foo[n+1]);
        memset( q, 0, sizeof(q));

        for(i=2; i<=n; i++)
        {
            for(j=i-1; j>0; j--)
            {
                if(foo[j].first<=foo[i].second.first)
                {
                    q[i]=j;
                    break;
                }
            }
        }

        memset( opt, -1, sizeof(opt));
        ans = gemini(n);
        printf("%d\n",ans);
    } //tc

return 0;
}
