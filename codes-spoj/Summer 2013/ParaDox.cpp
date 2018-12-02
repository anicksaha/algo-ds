/* SPOJ_PARADOX */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>


using namespace std;


int main()
{

    int n,implies[101],state[101];
    vector<int>implied_by[101];
    bool vis[101],claims[101];
    string str;

    while(1)
    {
        cin>>n;

        if(n==0)
            return 0;

        for(int i=1;i<=n;i++)
        {
            vis[i]=false;
            claims[i]=false;
            //state[i]=false;
            state[i]=true;
            implied_by[i].clear();
        }

        stack<int> q;

        for(int i=1;i<=n;i++)
        {
            cin>>implies[i];

            cin>>str;

            if(str[0]=='t')
            {
                claims[i]=true;
            }

            implied_by[implies[i]].push_back(i);
            q.push(i);
        }

        bool good=true;

        while(q.size()>0)
        {

            if(vis[q.top()])
            {
                q.pop();
                continue;
            }


            int curr=q.top();
            q.pop();

            vis[curr]=true;
            //cout<<state[curr]<<" "<<claims[curr]<<" "<<curr<<endl;

            bool imp=not(state[curr] xor claims[curr]);
            //cout<<imp<<endl;


            // T T T
            // T F F
            // F T F
            // F F T
            // !(xor)




            if(!vis[implies[curr]])
            {
                state[implies[curr]]=imp;
                q.push(implies[curr]);
            }

            else if(state[implies[curr]]!=imp)
            {
                good=false;
                break;
            }



            // now check impliers

            for(int i=0;i<implied_by[curr].size();i++)
            {
                if(!good) break;

                imp=not(state[curr] xor claims[implied_by[curr][i]]);


                // T T T
                // T F F
                // F T F
                // F F T
                // !(xor)


                if(!vis[implied_by[curr][i]])
                {
                    state[implied_by[curr][i]]=imp;
                    q.push(implied_by[curr][i]);
                }
                else if(state[implied_by[curr][i]]!=imp)
                {
                    good=false;
                    break;
                }
            } // For | impliers


        }  // while q.size()


        if(good)
            printf("NOT PARADOX\n");
        else
            printf("PARADOX\n");

    }  // While loop

    return 0;
}
