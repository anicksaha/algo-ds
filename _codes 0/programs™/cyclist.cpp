#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        double foo[n][n];
        memset(foo, 0.0, sizeof foo);
        double temp;
        int a,b;
        while(1)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            scanf("%lf",&temp);
            if(a==-1)
                break;
            foo[a-1][b-1]=foo[b-1][a-1]=temp;
        }

        for(int k = 0; k < n ; k++ )  //The "safety-factor" of a path from hostel to college is the least score of a road on that path
            for(int i = 0; i < n ; i++ )
                for(int j = 0; j < n ; j++ )
                    foo[i][j] = max( foo[i][j], min ( foo[i][k], foo[k][j] ) ) ;

         printf("%.6lf\n", foo[0][n-1]) ;
    }
    return 0;
}
