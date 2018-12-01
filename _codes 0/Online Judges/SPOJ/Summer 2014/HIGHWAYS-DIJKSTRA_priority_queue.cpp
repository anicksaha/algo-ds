#include<bits/stdc++.h>
using namespace std;
#define INF 10000000

int dist[1000001];

struct edge
{
	int v;
	int w;
};
vector<edge> adj[1000001];

bool operator<(edge a, edge b)
{
	if(a.w < b.w)
        return true;
    return false;
}

void dijkstra(int N,int S,int T)
{
    for(int i=0; i<=N; i++)
		dist[i]=INF;

	priority_queue<edge> q;
	q.push((edge){S,0});
	dist[S] = 0;

	while(!q.empty())
    {
		edge X = q.top();
		q.pop();

		for(int i=0;i<adj[X.v].size();i++)
        {
			edge k = adj[X.v][i];
			if(dist[X.v]+k.w<dist[k.v])
            {
				dist[k.v]=dist[X.v]+k.w;
				q.push(k);
			}
		}
	} // While
}

int main()
{
	int t,N,M,S,T;
	int u,v,w;
	scanf( "%d", &t );

	while(t--)
    {
		scanf("%d%d%d%d",&N,&M,&S,&T);

		for(int i=0;i<M;i++)
        {
			scanf("%d%d%d",&u,&v,&w);
			adj[u].push_back((edge){v,w}); // Adjacency List
			adj[v].push_back((edge){u,w}); // Adjacency List
		}

		dijkstra(N,S,T);

		if(dist[T]!=INF )
            printf("%d\n",dist[T]);
        else
            printf("NONE\n");
	} // TC
	return 0;
}
