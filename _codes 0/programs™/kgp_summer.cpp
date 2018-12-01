#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>

#define S(a) scanf("%d",&(a))
#define P(a) printf("%d",(a))
#define min(a,b) ((a)<(b)?(a):(b))
#define NL printf("\n")
#define sqr(a) ((a)*(a))


using namespace std;

int cost[2502][2502];

int main()
{
    int mi,u;

    int n,q,g,t,ans,x,y,x1,y1,s;

    S(t);

    vector<pair<int,int> > coor; // for storing coordinates of trees

    while(t--)
    {

        coor.clear();

        S(n);

        g=n;

        while(g--)
        {
            S(x);
            S(y);
            coor.push_back(make_pair(x,y)); // storing coordinates
        }

        S(x);
        S(y);

        S(x1);
        S(y1);

        cost[0][0]=0;

        cost[0][n+1]=cost[n+1][0]=sqr(x-x1)+sqr(y-y1); // source $$ target



        for(int i=0;i<n;i++)
        {
            cost[i+1][0]=cost[0][i+1]=sqr(x-coor[i].first)+sqr(y-coor[i].second); // source $$ trees
            cost[i+1][n+1]=cost[n+1][i+1]=sqr(x1-coor[i].first)+sqr(y1-coor[i].second); // target $$ trees
        }


        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                 cost[j][i]=cost[i][j]=sqr(coor[i-1].first-coor[j-1].first)+sqr(coor[i-1].second-coor[j-1].second); // distance of trees with respect to each other


        int dist[n+2];


        for(int i=0;i<n+2;i++)
            dist[i]=cost[0][i]; // initialising dist



        bool visited[n+2];

        memset(visited,false,sizeof visited); // setting visited to false

        visited[0]=true; // source is visited initially



        for(int i=0;i<n+2;i++)
        {

            mi=9999999;

            for(int m=0;m<n+2;m++)  // extracting minimum among not visited elements
            {
                if(!visited[m] && dist[m]<mi)
                {
                    mi=dist[m];
                    y=m;
                }
             }

            //u=mi;

            visited[y]=true; // setting visited to true


            for(int j=0;j<n+2;j++)
            {
                if(!visited[j])
                {
                    dist[j]=min(dist[j],dist[y]+cost[y][j]); // checking if smaller distance exists
                }
            }

         }


         P(dist[n+1]);

         NL;

    }

    return 0;

}
