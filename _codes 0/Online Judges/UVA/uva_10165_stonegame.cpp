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
#include<set>
#include <functional>
#include <bitset>
 
using namespace std;
 
typedef long long int ll;

int main()
{
  ll t,n,temp,ans,i,j;
  t=1;
  while(t)
   {
     cin>>n;
     if(n==0)
       break;
     ans=0;
     for(i=0;i<n;i++) 
      {
           cin>>temp;
           ans=ans^temp;
      }
    
     if(ans==0)
       cout<<"No"<<endl;
     else
       cout<<"Yes"<<endl;
     }
return 0;
}