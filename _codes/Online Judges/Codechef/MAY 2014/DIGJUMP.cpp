#include<bits/stdc++.h>
using namespace std;

struct data
{
   int dist;
   int val;
   data()
   {
       dist=1000000;
   }
}a[100001];

int n;
char str[100001];
bool visited[100001]; // Nodes :: Index
bool _visited[10];
vector<int> vec[10];  // Stores the indexes of i


void bfs(int x)
{
    memset(visited,false,sizeof(visited));
    memset(_visited,false,sizeof(_visited));
    queue<int> S;
    S.push(x);
    a[x].dist=0;
    visited[x]=true;
    //_visited[a[x].val]=true;

    while(!S.empty())
    {

        int current=S.front();
        S.pop();
        int VALUE=a[current].val;

        if(!_visited[VALUE])
        {
        _visited[VALUE]=true;
        for(int i=0;i<vec[VALUE].size();i++)
        {
            if(!visited[vec[VALUE][i]])
            {
                visited[vec[VALUE][i]]=1;
                a[vec[VALUE][i]].dist=a[current].dist+1;
                S.push(vec[VALUE][i]);
            }
        }
        } //
        //
        if((current-1)>=0)
        {
            if(!visited[current-1])
            {
                visited[current-1]=1;
                a[current-1].dist=a[current].dist+1;
                S.push(current-1);
             }
        }
        //
        if((current+1)<n)
        {
            if(!visited[current+1])
            {
                visited[current+1]=1;
                a[current+1].dist=a[current].dist+1;
                S.push(current+1);
            }
        }


    } // while
}

int main()
{
    scanf("%s",str);

    for(int i=0;str[i]!='\0';i++)
    {
      a[i].val=str[i]-'0';
      vec[a[i].val].push_back(i);
    }

    n=strlen(str);
    bfs(0);
    printf("%d",a[n-1].dist);
    return 0;
}
