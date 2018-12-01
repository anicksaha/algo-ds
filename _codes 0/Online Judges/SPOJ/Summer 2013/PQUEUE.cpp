#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int test, n, myjob, prio, i, t;

    ios::sync_with_stdio(false);

    cin >> test;


    while(test--)
    {
        queue< pair<int,int> > Q;
        priority_queue< int > PQ;

        cin >> n >> myjob;

        for(i=0; i<n; i++)
        {
            cin >> prio;
            PQ.push(prio);
            Q.push(make_pair(i,prio));
        }



        t = 0;

        while(!Q.empty())
        {
            i = Q.front().first;
            prio = Q.front().second;

            Q.pop();

            if(prio != PQ.top())
                Q.push(make_pair(i,prio));
            else
            {
                t++;
                PQ.pop();
                if(i==myjob) break;
            }
        }

        cout << t << endl;

    } // TC

    return 0;
}
