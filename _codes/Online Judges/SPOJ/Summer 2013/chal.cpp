#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<cstdio>

using namespace std;

static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()
{
    return alphanum[rand() % stringLength];
}

int main()
{
    //cout<<stringLength<<endl;
    int t,n,h;
    cin>>t>>n>>h;

    while(t--)
    {
        for(int yy=0;yy<n;yy++)
        {
            string s="";

            for(int i = 0; i <9; ++i)
            {
                s += genRandom();
            }

            cout<<s<<endl;
            fflush(stdout);

        }

        fflush(stdout);
        int temp;
        fflush(stdin);
        cin>>temp;



    }

    return 0;

}
