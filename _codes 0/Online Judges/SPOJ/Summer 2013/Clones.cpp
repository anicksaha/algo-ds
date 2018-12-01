#include<iostream>
#include<map>
#include<cstring>
#include<fstream>

using namespace std;

int main()
{
    int n,m;

    //freopen("C:\\Users\\Anick\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\Anick\\Desktop\\out.txt","w",stdout);

    while(1)
    {

        cin>>n>>m;
        if(n==0 && m==0 )
            break;

        map<string,int>foo;
        map<string,int>::iterator it;
        int mask[n];
        memset(mask,0,sizeof(mask));

        string s;

        for(int i=0;i<n;i++)
        {
            cin>>s;
            foo[s]++;
        }

        for(it=foo.begin();it!=foo.end();it++)
        {
            int temp=(*it).second;
            //cout<<(*it).first<<endl;
            temp--;
            mask[temp]++;
        }

        for(int i=0;i<n;i++)
            cout<<mask[i]<<endl;


    }

    return 0;
}
