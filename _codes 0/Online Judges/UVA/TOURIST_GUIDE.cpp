using namespace std;

#include <iostream>
#include <cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<algorithm>

#include<sstream>

#include<map>


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

    int citymap=0;

    bool start=true;

    while(cin>>n)
    {

        if(n==0)
            break;


        //cout<<endl;

        if(!start)
            printf("\n");

        start=false;


        map <string, int > foo;
        map <int, string > bar;

        int zz=1;

    	vector< vector<int> > ad(110);

        string s,s1;

        for(int i=1;i<=n;i++)
        {
            cin>>s;
            foo[s]=zz;
            bar[zz]=s;
            zz++;
        }

        cin>>m;

        for(int i=1;i<=m;i++)
        {
            cin>>s>>s1;
            ad[foo[s]].push_back(foo[s1]);
    	    ad[foo[s1]].push_back(foo[s]);
        }




		memset(visited, false, sizeof(visited));

		for(int i=0;i<=n;i++)
    	{
    		a[i].numChild=0;
    		a[i].isAr=false;
    	}



		for(int i=1;i<=n;i++)
		{
		    if(!visited[i])
		    {
		        a[i].dis=0;
		        dfs(i,ad);
		    }

		}


		//a[1].dis=0;
		//dfs(1,ad);


    	int ctr=0;

        vector<string> ans_set;

   		for(int i=1;i<=n;i++)
    	{
    		if(a[i].isAr)
    		{
				ctr++;
                ans_set.push_back(bar[i]);
    		}
    	}

        citymap++;

    	cout<<"City map #"<<citymap<<": "<<ctr<<" camera(s) found"<<endl;


        sort(ans_set.begin(),ans_set.end());

        for(int jj=0;jj<ans_set.size();jj++)
            cout<<ans_set[jj]<<endl;




	} // tc

	return 0;
}
