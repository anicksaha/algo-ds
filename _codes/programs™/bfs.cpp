#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#define scan(a) scanf("%d",&a)
using namespace std;
int main()
{
    void bfs(vector <vector <int> > &,int,int,int);
    int n,m,i,x,y,start;
    scan(n);
    scan(m);
    scan(start);
    vector <vector <int> > vertex(1000);
    for(i=0;i<m;i++)
    {
        scan(x);
        scan(y); 
        vertex[x].push_back(y);
        vertex[y].push_back(x);
      
    }
    bfs(vertex,n,m,start);
}
void bfs(vector <vector <int> > &vertex,int n,int m,int start)
{
    int front,i;
    vector <int> visited(n,false);
    queue <int> QUEUE;
    QUEUE.push(start);
    visited[start]=true;
    while(!QUEUE.empty())   
    {
        front=QUEUE.front();
        cout<<front<<" ";
        queue.pop();
        for(i=0;i<vertex[front].size();i++)
        {
            if(!visited[vertex[front][i]])
            {
                visited[vertex[front][i]]=true;
                QUEUE.push(vertex[front][i]);
            }
        }
    }
}