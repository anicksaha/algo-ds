
//<--anick_7-->//
 
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cassert>
#include<bitset>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<list>
#include<cstring>
#include<map>
#include<signal.h>
#include<set>
 
using namespace std;


long long int gemini(long long int a,long long int b,long long int c)
{
    long long x=1,y=a; 
     while(b > 0)
            {
             if(b%2 == 1)
                       {
                         x=(x*y)%c;
                        }
             y = (y*y)%c; 
              b /= 2;
         }
    return x%c;
}


int main()
{
 long long int a,b,c;
 while(cin>>a>>b>>c)
 {
 cout<<gemini(a,b,c)<<endl;
 } 
return 0;
}
