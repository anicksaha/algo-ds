#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{

    string s,r;
    while(1)
    {
        cin>>s;
        if(s=="#")
            break;

        r=s;
        sort(r.begin(),r.end());
        next_permutation(s.begin(),s.end());
        //cout<<r;
        if(r==s)
            cout<<"No Successor"<<endl;
        else
            cout<<s<<endl;
    }


}
