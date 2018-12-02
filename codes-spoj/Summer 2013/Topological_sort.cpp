// SPOJ Project File Dependencies
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
#include<set>
#include<queue>

using namespace std;

set<int>a[120];
int indeg[120];
vector<int>ans;
set<int> temp;

void topo()
{
     while(!temp.empty())
     {
        int x=*(temp.begin());
        ans.push_back(x);
        temp.erase(temp.begin());

        set<int>::iterator it;
        for(it=a[x].begin();it!=a[x].end();it++)
        {
            indeg[*it]--;
            if(indeg[*it]==0)
                temp.insert(*it);
        }
     } // while
}


int main()
{

    int n,m;
    scanf("%d %d",&n,&m);

    int node,depends,x;

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&node,&depends);

        for(int j=0;j<depends;j++)
        {
           scanf("%d",&x);
           a[x].insert(node);
        }

        indeg[node]+=depends;
     }


    for(int i=1;i<=n;i++)
        if(indeg[i]==0)
            temp.insert(i);

    topo();

    vector<int>::iterator it;


    for( it=ans.begin();it!=ans.end();it++)
        printf("%d ",*it);

    printf("\n");

}
