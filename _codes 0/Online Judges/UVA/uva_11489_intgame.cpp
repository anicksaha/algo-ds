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
 
#define SL(x) scanf("%lld",&x)
#define S(x) scanf("%d",&x)
#define SS(x) scanf("%s",s)
#define P(x) printf("%d",x)
#define PL(x) printf("%lld",x)
#define PS(x) printf("%s",x)
#define NL printf("\n")
#define FOR(x) for(int i=0;i<x;i++)
#define FORREV(x) for(int i=x;i>=0;i++)
#define W(x) while(x--)


int main ()

{


    ll t;

    SL(t);

    int ctr = 0;

 

    W(t)
    {

        char num [1000];

        scanf ("%s", num);

 

        int freq [11];

        memset (freq, 0, sizeof (freq));

        int l=strlen(num);

        int sum = 0;

 

        for ( int i = 0; i<l; i++ ) 
        
        {

            sum += num [i] - '0';

            freq [num [i] - '0']++;

        }

 

        int temp = freq [3] + freq [6] + freq [9];

         bool win = true;

 

     if ( sum % 3 == 0 ) {

            if ( temp % 2 == 0 ) win = false;
  
                 }

 

        else if ( sum % 3 == 1 ) {

            if ( freq [1] || freq [4] || freq [7] ) {

                if ( temp % 2==1 ) win = false;

                }

            else win = false;

           } 

 

        else {

            if ( freq [2] || freq [5] || freq [8] ) {

                if ( temp % 2==1 ) win = false;

               }

            else win = false;

            }


        printf ("Case %d: ", ++ctr);

        if ( win ) printf ("S\n");

        else printf ("T\n");

    }

  return 0;

}
