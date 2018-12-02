#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>

#define S(a) scanf("%d",&(a))
#define P(a) printf("%d",(a))
#define min(a,b) ((a)<(b)?(a):(b))
#define NL printf("\n")
#define sqr(a) ((a)*(a))

#define sex 999999
using namespace std;

int cost[10001][10001];

int main()
{
    int mi,u;

    int n,q,g,t,ans,x,y,x1,y1,s,e;
    int target;

    S(t);

    while(t--)
    {

        //coor.clear();

        S(n);
        S(e);

        S(x);
        S(target);

        g=e;

        int cost[n+1][n+1];

        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                cost[i][j]=sex;
        //memset(cost, -1, sizeof cost);



        for ( int i=1;i<=e;i++)
        {
            S(x1);
            S(y1);
            int z;
            S(z);
            cost[x1][y1]=z;
            cost[y1][x1]=z;
        }






        int dist[n+1];


        for(int i=1;i<=n;i++)
            dist[i]=cost[x][i]; // initialising dist



        bool visited[n+1];

        memset(visited,false,sizeof visited); // setting visited to false


        visited[x]=true; // source is visited initially





        for(int i=1;i<=n;i++)
        {

            mi=9999999;

            for(int m=1;m<=n;m++)  // extracting minimum among not visited elements
            {
                if(!visited[m] && dist[m]<mi)
                {
                    mi=dist[m];
                    y=m;
                }
             }

            //u=mi;

            visited[y]=true; // setting visited to true


            for(int j=1;j<=n;j++)
            {
                if(!visited[j])
                {
                    dist[j]=min(dist[j],dist[y]+cost[y][j]); // checking if smaller distance exists
                }
            }

         }



        if(dist[target]>10000)
                {
                    printf("NONE");
                    NL;
                    continue;
                }

         P(dist[target]);

         NL;

    }  // TC

    return 0;

}


