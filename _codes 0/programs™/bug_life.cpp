#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#include<utility>
#include<climits>



using namespace std;

bool visited[2005];
bool marker[2005];

void dfs(vector <vector <int> > & , int );


int main()
{
    int t,n,m,v1,v2,k=0;
    bool flag;

    scanf("%d",&t);

    while(t--)
    {
        flag=true;
        k++;

        scanf("%d",&n);
        scanf("%d",&m);

        vector<vector<int> > vertex(n+1);       // adjacency list

        memset(visited,false,sizeof visited);
        memset(marker,false,sizeof marker);


        while(m--)
        {
            scanf("%d",&v1);
            scanf("%d",&v2);
            vertex[v1].push_back(v2);
            vertex[v2].push_back(v1);
        }


        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                dfs(vertex,i);
            }
        }


        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<vertex[i].size();j++)
            {
                if(marker[i]==marker[vertex[i][j]])
                {
                    flag=false;
                    break;
                }
            }
        }


        if(!flag)
            printf("Scenario #%d:\nSuspicious bugs found!\n",k);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n",k);

    }

    return 0;

}



void dfs(vector <vector <int> > &vertex,int f1)
{
    int top,i;

    marker[f1]=true;
    stack<int> s;
    s.push(f1);
    while(!s.empty())
    {

        top=s.top();

        s.pop();
        visited[top]=true;
        for(i=0;i<vertex[top].size();i++)
        {
            if(!visited[vertex[top][i]])
            {
                s.push(vertex[top][i]);
                visited[vertex[top][i]]=true;
                marker[vertex[top][i]]=!marker[top];

            }
        }

    }
}
