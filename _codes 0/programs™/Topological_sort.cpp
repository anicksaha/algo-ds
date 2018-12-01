using namespace std;
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

int indeg[200],adj[200][200],included,n,m;
vector<int> ans; // stores the final answer...

void topsort(void)
{
    int i,j,k;

    while(included<n)
    {
        for(i=1;i<=n;i++)
        if(!indeg[i]) // choose vetrex with zero indegree...
        {
            ans.push_back(i);
            included++;
            indeg[i]=-1;
            for(j=1;j<=n;j++) // delete all egdes originating from this vertex...
            if(adj[i][j])
            {
                adj[i][j]=0;
                indeg[j]--;
            }
        }
    }
    return;
}

int main()
{
    int i,j,k,x,y;

    while(cin>>n>>m)
    {
        if((n==0)&&(m==0))
        break;

        memset(indeg,0,sizeof(indeg));
        memset(adj,0,sizeof(adj));

        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            adj[x][y]=1; // adjacency matrix representation...
            indeg[y]++; // record indegree of all vertices...
        }

        included=0; // initially no vertex is included in ans vector...
        topsort();

        for(i=0;i<ans.size()-1;i++)
        cout<<ans[i]<<" "; // print contents of the vector ans...
        cout<<ans[i]<<endl;

        ans.clear(); // clear the given vector...
    }
    return 0;
}
