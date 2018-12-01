#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    gcd(b,a%b);
}

int main()
{

    int f,s,g,u,d;

    while(scanf("%d%d%d%d%d",&f,&s,&g,&u,&d)!=EOF)
    {
        if(s==g)
        {
            printf("0\n");
            continue;
        }

        if(u==0&&d!=0)
        {
            if((s-g)>0&&(s-g)%d==0)
            printf("%d\n",(s-g)/d);
            else
            printf("use the stairs\n");
            continue;
        }

        else if(d==0&&u!=0)
        {
            if((g-s)>0&&(g-s)%u==0)
            printf("%d\n",(g-s)/u);
            else
            printf("use the stairs\n");
            continue;
        }

        else if(d==0&&u==0)
        {
            printf("use the stairs\n");
            continue;
        }



        if((g-s)%gcd(u,d)!=0)
        {
            printf("use the stairs\n");
            continue;
        }

        int counts=0;

        while(s!=g)
        {
            if(s+u>f && s-d<1)
                break;
            else if(s+u<=f && s<=g)
                s+=u;
            else if(s-d>=1 && s>=g)
                s-=d;
            else if(s-d<1 && s+u<=f)
                s+=u;
            else if(s+u>f && s-d>=1)
                s-=d;



            counts++;
        }
        if(s==g)
            printf("%d\n",counts);
        else
            printf("use the stairs\n");
    }

    return 0;
}

