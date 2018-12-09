// Kosaraju’s algorithm
// Also see tarjan's algo

#include<bits/stdc++.h>
using namespace std;

vector<int> graph[5002];
vector<int> trans_graph[5002];
bool visited[5002];

int component_id[5002];
bool valid_component[5002];

vector<int> Stack; // DFS 2 Stack !

int scc_cnt,temp,maxm;


void dfs1(int v)
{
    int i;
    visited[v]=true;
    for(i=0;i<graph[v].size();i++)
        if(!visited[graph[v][i]])
            dfs1(graph[v][i]);
    Stack.push_back(v);
}

void dfs2(int v,int id)
{
    int i;
    visited[v]=true;
    component_id[v]=id;

    temp++;
    for(i=0;i<trans_graph[v].size();i++)
        if(!visited[trans_graph[v][i]])
            dfs2(trans_graph[v][i],id);
}

void scc(int n)
{
    memset(visited, false, sizeof(visited));
    memset(valid_component, true, sizeof(valid_component));

    Stack.clear();

    //DFS 1
    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs1(i);

    memset(visited, false, sizeof(visited));

    //DFS 2
    scc_cnt=0;

	for(int i=Stack.size()-1;i>=0;i--)
        if(!visited[Stack[i]])
        {
            dfs2(Stack[i],scc_cnt++);
            maxm=max(maxm,temp);
            temp=0;
        }

    for(int i=1;i<=n;i++)
        for(int j=0;j<graph[i].size();j++)
                if(component_id[i] != component_id[graph[i][j]])
                    valid_component[component_id[i]]=false;
} // SCC


int main()
{
    int n,from,to;

    while(1)
    {
        cin>>n;
        if(n==0)
            break;

        for(int i=1;i<=n;i++)
        {
            graph[i].clear();
            trans_graph[i].clear();
        }

        int m;
        cin>>m;
        while(m--)
        {
            cin>>from>>to;
            graph[from].push_back(to);
            trans_graph[to].push_back(from);
        }

        maxm=0;
        scc(n);

        for(int i=1;i<=n;i++)
            if(valid_component[component_id[i]])
                cout<<i<<" ";
        cout<<endl;

    }
    return 0;
}

