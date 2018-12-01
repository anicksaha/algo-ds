#include<bits/stdc++.h>
using namespace std;


#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
#define lcm(a,b)  { return a*b/gcd(a,b);  }


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
#define PS(x) printf("%s",x)
#define FOR(x) for(int i=1;i<=x;i++)
#define f_FOR(p,q,r) for(int p=q;p<=r;p++)
#define REV(x) for(int i=x;i>0;i--)
#define r_REV(p,q,r) for(int p=q;p<=r;p--)
#define W(x) while(x--)
#define TC int t;for(scanf("%d",&t);t>0;t--)
#define NL printf("\n")


int main()
{
    int n,i;
    TC
    {
         int n,i,j;
         int H[501]={0};
         int K[501]={0};
         int DP[1001];
         int Count=0,foo=0;
         S(n);
         for(i=0;i<n;i++)
         {
            scanf("%d",&H[i]);
            H[i] = 2*H[i];
         }

        foo=*max_element(&H[0],&H[n]);


        DP[0]=1;

        for(i=1;i<foo+1;i++) DP[i]=1001;

        for(i=0;i<n;i++) scanf("%d",&K[i]);

        for(i=0;i<n;i++)
         {
            DP[K[i]]=1;
            for(j=K[i];j<=foo;j++)
                DP[j] = min(DP[j], DP[j-K[i]]+1);
         }

        for(i=0;i<n;i++)
            Count+=DP[H[i]];

        printf("%d\n",Count);
    }
    return 0;
}
