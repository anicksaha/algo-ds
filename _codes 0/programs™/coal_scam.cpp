/*
    anick saha
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int u,v,w;
};

vector <int> size,parent;

bool comp(edge a,edge b)
{
    if(a.w < b.w)
        return true;
    else
        return false;
}

bool comp1(edge a, edge b)
{
    if(a.w > b.w)
        return true;
    else
        return false;
}

int find_set(int x)
{
    if(x!=parent[x])
        parent[x]=find_set(parent[x]);
    return parent[x];
}


int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {

        int n,m1,m2;

        long long int mincost=0;
        long long int maxprofit=0;

        scanf("%d%d%d",&n,&m1,&m2);

        size.clear();
        parent.clear();
        size.resize(n,0);
        parent.resize(n,0);

        for(int i=0;i<n;++i)       //individual sets
        {
            size[i]=1;
            parent[i]=i;
        }

        vector <edge> E(m1);
        vector <edge> E1(m2);


        for(int i=0;i<m1;++i)       //other companies
        {
            scanf("%d%d%d",&(E[i].u),&(E[i].v),&(E[i].w));
        }


        for(int i=0;i<m2;++i)       //chef's company
        {
            scanf("%d%d%d",&(E1[i].u),&(E1[i].v),&(E1[i].w));
        }


        sort(E.begin(),E.end(),comp);  //increasing order
        sort(E1.begin(),E1.end(), comp1);  //decreasing order



        for(int i=0;i<m2;++i)   //Max Spanning Tree
        {
            int p=find_set(E1[i].u);
            int q=find_set(E1[i].v);

            if(p!=q)
            {
                if(size[p]<size[q])
                {
                    parent[p]=q;
                    size[q]+=size[p];
                }
                else
                {
                    parent[q]=p;
                    size[p]+=size[q];
                }

                mincost+=E1[i].w;
                maxprofit+=E1[i].w;
            }
        }


        for(int i=0;i<m1;++i)  //Minimum Spanning Tree
        {
            int p=find_set(E[i].u);
            int q=find_set(E[i].v);

            if(p!=q)
            {
                if(size[p]<size[q])
                {
                    parent[p]=q;
                    size[q]+=size[p];
                }
                else
                {
                    parent[q]=p;
                    size[p]+=size[q];
                }

                mincost+=E[i].w;
            }
        }


        bool foo=false;

        for(int i=0;i<=n;++i)
        {
            if(size[i]==n)
            {
                foo=true;
                break;
            }
        }

        if(foo)
            printf("%lld %lld\n", maxprofit, mincost);
        else
            printf("Impossible\n");

    } //Test Case ending loop

return 0;

}
