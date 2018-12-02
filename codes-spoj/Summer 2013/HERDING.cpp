/*
    nik.93
    SPOJ : HERDING
    algo : flood-fill
*/

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    char foo[n][m];
    int visited[n][m], c=1;

    memset(visited, 0, sizeof(visited));

    string s;

    int ans=0, a, b;

    // NORTH - 1 EAST -2 SOUTH -3 WEST -4 :D

    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
            foo[i][j]=s[j];

    }


    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {

            if(visited[i][j]==0)
            {
                a = i;
                b = j;
                while(visited[a][b]==0)
                {
                    visited[a][b]=c;

                    if(foo[a][b]=='N')
                        a--;
                    else if(foo[a][b]=='E')
                        b++;
                    else if(foo[a][b]=='S')
                        a++;
                    else if(foo[a][b]=='W')
                        b--;
                }

                if (visited[a][b] == c )
                    ans++;

                c++;
            }
        }


    cout<<ans<<endl;

    return 0;

}
