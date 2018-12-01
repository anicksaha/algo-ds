#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;
pair<int,int> ti[100000];

// second : starting tym
// first : end tym

int greedy_activity_selector()
{
    int ctr=1;
    int k=0,i;

    for(i=1;i<n;i++)
    {
        if(ti[i].second>=ti[k].first)
        {
            ctr++;
            k=i;
        }
    }

    return ctr;
}


int main()
{
    int t,i,ans,start,end;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&start,&end);
            ti[i]=make_pair(end,start);  // sort by ending time
        }

        sort(ti,ti+n);


        ans=greedy_activity_selector();

        printf("%d\n",ans);
    }

    return 0;
}
