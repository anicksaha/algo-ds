#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<cstring>
#include<cctype>

using namespace std;
typedef int ll;

int main()
{
    string s;
    int l,i,j,a,b,c,d;
    while(cin>>s)
    {
        l=s.length();
        a=b=c=d=0;

        for(int i=0;i<l;i++)
        {
            if(i%2)
            {
                if(islower(s[i]))
                {
                    a++;
                }
                else
                {
                    b++;
                }
            }
            else
            {
                if(islower(s[i]))
                {
                    d++;
                }
                else
                {
                    c++;
                }
            }

        }
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        cout<<min(a+c,b+d)<<endl;
    }
    return 0;
}
