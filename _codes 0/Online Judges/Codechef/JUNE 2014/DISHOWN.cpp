#include<bits/stdc++.h>

using namespace std;


int size[10010];
int parent[10010];

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

        int n,q,type,x,y;
        scanf("%d",&n);

        for(int i=1;i<=n;i++)      //individual sets
        {
            scanf("%d",&size[i]);
            parent[i]=i;
        }

        scanf("%d",&q);

        for(int i=1;i<=q;++i)  //Minimum Spanning Tree
        {
            scanf("%d",&type);

            if(type==1)
            {
                scanf("%d",&x);
                printf("%d\n",find_set(x));
            }
            else
            {
                scanf("%d%d",&x,&y);

                int p=find_set(x);
                int q=find_set(y);

                if(p!=q)
                {
                    if(size[p]<size[q])
                        parent[p]=q;
                    else if(size[p]>size[q])
                        parent[q]=p;
                    else
                    {

                    }
                }
                else
                    printf("Invalid query!\n");
            }
        }

     } //Test Case ending loop

return 0;

}
