/*
    anick saha
*/

#include<sstream>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<functional>
#include<numeric>
#include<bitset>
#include<utility>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<iterator>
#include<ctime>


using namespace std;


#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)


typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;


#define SL(x) scanf("%lld",&x)
#define SLL(x) scanf("%llu",&x)
#define S(x) scanf("%d",&x)
#define SS(x) scanf("%s",s)
#define P(x) printf("%d",x)
#define PL(x) printf("%lld",x)
#define PLL(x) printf("%llu",x)
#define FOR(p,q,r) for(int p=q;p<=r;p++)
#define REV(p,q,r) for(int p=q;p>=r;p--)
#define W(x) while(x--)
#define TC int t;for(scanf("%d",&t);t>0;t--)
#define NL printf("\n")


#define M 1000000007


int main()
{


    vector<pair<int,string> > v;
    string s;
    pair<int, string> temp;
    int age;

    while(cin>>s>>age)
    {
        temp=make_pair(age,s);
        //cout<<temp.second<<endl;
        v.push_back(temp);
    }


    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());


    /*

    for(int o=0;o<v.size();o++)
        cout<<v[o].first<<" "<<v[o].second<<endl;


    cout<<"\n\n";

    */

    vector<string> foo;
    int bar;

    int max=v.size();

    vector<string> ans;

    int i,j,k,next;
    next=0;
    i=0;


    while(1)
    {
        foo.clear();
        bar=v[next].first;
        //i++;
        while(v[i].first==bar)
        {
            //cout<<v[i].first<<" "<<v[i].second<<endl;
            foo.push_back(v[i].second);
            i++;
        }


        next=i;

        sort(foo.begin(),foo.end());

        for(j=0;j<foo.size();j++)
        {
            ans.push_back(foo[j]);
            //cout<<foo[j]<<endl;
        }

        if(i>=v.size())
            break;
    }

    for(i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;


    return 0;

}
