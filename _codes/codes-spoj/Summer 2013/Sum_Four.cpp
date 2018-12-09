#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int a[4000],b[4000],c[4000],d[4000],i,j;
    int n,foo;
    long long int ans=0;
    vector<int>v;

    cin>>n;

    for(i=0;i<n;i++)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            v.push_back(a[i]+b[j]);

    sort(v.begin(),v.end());

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            foo=-(c[i]+d[j]);
            //ans+=(upper_bound(v.begin(),v.end(),foo) - lower_bound(v.begin(),v.end(),foo));
            ans+=count(v.begin(),v.end(),foo);
        }

    printf("%lld",ans);
    return 0;
}
