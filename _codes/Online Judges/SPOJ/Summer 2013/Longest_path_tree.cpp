#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

vector<int> V[10010];
int vis[10010],dist[10010],k;
void dfs(int v,int n)
{
    vis[v]=1;
    dist[v]=n;
    for(int u=0;u<V[v].size();u++)
        if(!vis[V[v][u]])
            dfs(V[v][u],n+1);
}

int main()
{
    int n,t1,t2;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<=n;i++)
            V[i].clear(),vis[i]=0;

        for(int i=1;i<=n-1;i++)
        {
            scanf("%d%d",&t1,&t2);
            V[t1].push_back(t2);
            V[t2].push_back(t1);
        }

        dist[1]=0;
        dfs(1,0);

        /*
        for(int i=1;i<=n;i++)
            cout<<dist[i]<<" ";
        cout<<endl;
        */


        int node=1;
        /*
        for(int i=1;i<=n;i++)
            if(dist[i]>dist[node])
                node=i;
         */

        node= max_element(dist+1, dist+n+1) - (dist);

        memset(vis,0,sizeof(vis));
        // cout<<"node"<<node<<endl;

        dfs(node,0);

        /*
        for(int i=1;i<=n;i++)
            cout<<dist[i]<<" ";
        cout<<endl;
        */

        sort(dist+1,dist+n+1);
        cout<<dist[n]<<endl;


    }

    return 0;
 }
