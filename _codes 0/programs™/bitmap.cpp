#include<bits/stdc++.h>
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int dist[210][210],r,c;

vector<string> arr;

int IMAX=numeric_limits<int>::max();

void bfs()
{
    int x,y,nx,ny;

    pair<int,int> top;
    pair<int,int> p;

    queue<pair<int,int> > q;

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(arr[i][j]=='1')
            {
                dist[i][j]=0;
                q.push(make_pair(i,j));
            }

    while(!q.empty())
    {
        top=q.front();
        q.pop();
        x=top.first,y=top.second;

        for(int i=0;i<4;i++)
        {
            nx=x+dx[i],ny=y+dy[i];

            if(nx>=0 && nx<r && ny>=0 && ny<c && dist[nx][ny]>dist[x][y]+1)
            {
                dist[nx][ny]=dist[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }

    }  // While
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        arr.clear();
        scanf("%d%d",&r,&c);

        for(int i=0;i<r;i++)
        {
            string s;
            cin>>s;
            arr.push_back(s);
        }

        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            dist[i][j]=IMAX;

        bfs();

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                printf(" %d",dist[i][j]);
            printf("\n");
        }

    } //TC

    return 0;
}


