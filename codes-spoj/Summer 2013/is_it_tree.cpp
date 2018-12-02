#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int e,v;
    bool ans=true;
    cin>>v>>e;
    bool visited[v+1];
    memset(visited,false,sizeof(visited));

    int x,y;
    while(e--)
    {
        cin>>x>>y;

        if(visited[x]&&visited[y])
        {
            ans=false;
            //cout<<x<<y<<"@@"<<endl;
        }
        visited[x]=true;
        visited[y]=true;
    }

    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
