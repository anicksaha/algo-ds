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


int foo[2001][2001];


int main()
{



string a, b;

int t, cards, c, temp, len1, len2;






S(t);


cin.ignore();


  W(t)

    {

              S(cards);

//cout<<cards<<endl;

        getchar();

        //cin.ignore();

             getline(cin, a,'\n');
             getline(cin, b,'\n');

            //cin>>a>>b;

//cout<<a<<endl;
//cout<<b<<endl;

             len1=a.length();
             len2=b.length();


             for(int i=0;i<=len1;i++)
              foo[i][0]=i;



            for(int i=0;i<=len2;i++)
              foo[0][i]=i;


       for(int i=1;i<=len1;i++)
                for(int j=1;j<=len2;j++)

                        {
                            if( a[i-1]!=b[j-1])
                            {
                                 foo[i-1][j-1]++;
                            }

                            temp= MIN (foo[i][j-1]+1,foo[i-1][j]+1);
                            foo[i][j]= MIN(temp ,foo[i-1][j-1]);

                        }



                        c=foo[len1][len2];

                        cout<<"Rs. "<<(c*cards*2);

                       //cout<<c;

                        NL;


        }


  return 0;

}
