using namespace std;

#include <iostream>
#include <cstdio>
#include<bitset>
#include<vector>
#include<cstring>

#include<sstream>


    // Articulation Point

struct node
{
    int numChild;
    int dis;
    int back;
    bool isAr;
}a[110];


bool visited[110];


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


    while(cin>>n)
    {

        if(n==0)
            break;

        string _line1;
        getline(cin, _line1);

    	vector< vector<int> > ad(110);


        while(1)
        {
            //cout<<_line1<<endl;
            getline(cin, _line1);
            //cout<<_line1<<endl;

            stringstream line1(_line1);

            line1>>u;
            //cout<<"@"<<u<<endl;

            if(u==0)
                break;

            while(line1>>v)
    	    {
                //cout<<"@::: "<<v<<endl;
    		    ad[u].push_back(v);
    		    ad[v].push_back(u);
    	    }

        }





		memset(visited, false, sizeof(visited));

		for(int i=0;i<=n;i++)
    	{
    		a[i].numChild=0;
    		a[i].isAr=false;
    	}


        /*
		for(int i=1;i<=n;i++)
		{
		    if(!visited[i])
		    {
		        a[i].dis=0;
		        dfs(i,ad);
		    }

		}
		*/

		a[1].dis=0;
		dfs(1,ad);


    	int ctr=0;

   		for(int i=1;i<=n;i++)
    	{
    		if(a[i].isAr)
    		{
				ctr++;
    		}
    	}

    	printf("%d\n",ctr);

	} // tc

	return 0;
}
