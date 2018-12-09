#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair< int, int >

int main()
{

    int test, n, myjob, prio, i, t;

    ios::sync_with_stdio(false);

    cin >> test;


    while(test--)
    {
        queue< pii > Q;
        priority_queue< int > PQ;
        cin >> n >> myjob;

        for(i=0; i<n; i++)
        {
            cin >> prio;
            PQ.push(prio);
            Q.push(pii(i,prio));
        }


        while(!PQ.empty())
        {
            int temp=PQ.top();

            cout<<temp<<endl;
            PQ.pop();
        }



    } // TC

    return 0;
}
