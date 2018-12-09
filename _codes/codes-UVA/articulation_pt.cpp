using namespace std;
#include <iostream>
#include <cstdio>
#include<bitset>
#include<vector>
#include<cstring>

	// Articulation Point

struct node
{
    int numChild;
    int dis;
    int back;
    bool isAr;
}a[3100];


bool visited[3100];


void dfs(int x,vector< vector<int> > &ad)
{
   	visited[x]=true;
	a[x].back= a[x].dis;
    int size=ad[x].size();

	for(int i=0;i<size;i++)
    {
    	if(!visited[ad[x][i]])
    	{
   	 		a[x].numChild++;
    		a[ad[x][i]].dis = a[x].dis + 1;
    		dfs( ad[x][i],ad );

    		if(a[ad[x][i]].back>=a[x].dis && a[x].dis>0)
                a[x].isAr=true;

    		a[x].back=min(a[ad[x][i]].back, a[x].back);
    	}
    	else
    	{
    		a[x].back=min(a[ad[x][i]].dis, a[x].back);
    	}

    } //


	if(a[x].numChild>=2 && a[x].dis==0) // only checks the parent root
    	a[x].isAr=true;

}


int main()
{
    int t,n,m;
    int u,v;
    scanf("%d",&t);
    while(t--)
    {

    	vector< vector<int> > ad(3005);
    	//cin>>n>>m>>k;
    	scanf("%d%d",&n,&m);
    	//ad.clear();

    	for(int i=0;i<m;i++)
    	{
    		scanf("%d%d",&u,&v);
    		ad[v].push_back(u);
    		ad[u].push_back(v);
    	}

		memset(visited, false, sizeof(visited));

		for(int i=0;i<n;i++)
    	{
    		a[i].numChild=0;
    		a[i].isAr=false;
    	}

		a[0].dis=0;
    	dfs(0,ad);
    	int ctr=0;

   		for(int i=0;i<n;i++)
    	{
    		// cout<<i<<"-->"<<a[i].back<<endl;
    		if(a[i].isAr)
    		{
				ctr++;
    			// cout<< "$$ " <<i<<" back-"<<a[i].back<<endl;
    		}
    	}

    	int ans=ctr;
    	//cout<<ans<<endl;
    	printf("%d\n",ans);

	} // tc

	return 0;
}
