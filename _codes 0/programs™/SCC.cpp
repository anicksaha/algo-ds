/* 
    anicksaha
*/


/* 
  problem: soldiers and terrorrists (cqm 13)...
  algo: strongly connected component...
 
sample i/p:
3
2 
1 2 
2 1 
3 
1 1 2 3 
2 3 1 1 
2 
1 
2
 
sample o/p:
2
3
1
 
*/


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<sstream>

using namespace std;

vector<int> graph[102];
vector<int> trans_graph[102];
vector<int> stack;

bool visited[102]={false};
int scc_cnt,temp,maxm;
 

void dfs1(int v)
{
    int i;
    visited[v]=true;
    for(i=0;i<graph[v].size();i++)
        if(!visited[graph[v][i]])
            dfs1(graph[v][i]);
    stack.push_back(v);
}
 
void dfs2(int v)
{
    int i;
    visited[v]=true;
    temp++;
    for(i=0;i<trans_graph[v].size();i++)
        if(!visited[trans_graph[v][i]])
            dfs2(trans_graph[v][i]);
}
 
void scc(int n)
{
    int i;
    memset(visited, false, sizeof(visited));
    stack.clear();
    
    //DFS 1
    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs1(i);
 
    memset(visited, false, sizeof(visited));
 
    //DFS 2
    scc_cnt=1;
    
	for(i=stack.size()-1;i>=0;i--)
    {
        if(!visited[stack[i]])
        {
            dfs2(stack[i]);
            scc_cnt++;
            maxm=max(maxm,temp);
            temp=0;
        }
    }
}

 
int main()
{
    int t,n,from,to; 
    cin>>t;
    t++;
    while(t--)
    {
 
        string _line1,_line2;
        
        cin>>n;
        
        for(int i=1;i<=n;i++)
        {
            graph[i].clear();
            trans_graph[i].clear();
        }
        
        getline(cin,_line1);  //
        
        getline(cin,_line1); getline(cin,_line2);
        
        stringstream line1(_line1), line2(_line2);
        //getchar();

 
        while(line1>>from && line2>>to)
        {
            graph[from].push_back(to);
            trans_graph[to].push_back(from);
        }
            
        maxm=0;
        scc(n);
        
        cout<<maxm<<endl;
    }
    return 0;
}

