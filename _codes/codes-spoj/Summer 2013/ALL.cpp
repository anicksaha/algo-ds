using namespace std;
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>


int simulate(int current,vector<int> ndeps,const vector<vector<int> > deps,int n1,int n2)
{
    queue<int> dvd[2];
    vector<int> ::const_iterator it;

    for (int i=1;i<=n1+n2;i++)
        if(ndeps[i]==0)
            dvd[i>n1?1:0].push(i);

    int steps = 1;

    while(!dvd[0].empty() || !dvd[1].empty())
    {
        while (!dvd[current].empty())
        {
            int p = dvd[current].front();
            dvd[current].pop();

            for (it = deps[p].begin() ; it != deps[p].end() ; ++it)
                if(--ndeps[*it] == 0)
                    dvd[*it>n1?1:0].push(*it);
        }

        current ^= 1;
        steps++;
    }

    return steps;
}

int main()
{
    while (1)
    {
        int n1, n2, d;
        cin>>n1>>n2>>d;

        if (n1 == 0 && n2 == 0 && d == 0)
            break;

        vector<int> ndeps(n1+n2+1);
        vector<vector<int> >deps(n1+n2+1);

        for(int i=0;i<d;i++)
        {
            int x, y;
            cin>>x>>y;
            ndeps[x]++;                  // "x" depends on hw many jobs
            deps[y].push_back(x);        // who depends on "y"
        }

        printf("%d\n", min(simulate(0, ndeps, deps, n1, n2),simulate(1, ndeps, deps, n1, n2)));
    }

  return 0;
}


