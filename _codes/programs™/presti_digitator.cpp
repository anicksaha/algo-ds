#include<iostream>
#include <cstdio>
#include<map>

using namespace std;

map<int,int> foobar;

inline void foo()
{
    int a=0,b=1,c,i;
    foobar[1]=a;
    foobar[2]=b;
    for(i=3;i<=20;i++)
    {
        c=(a+b)*(i-1);
        foobar[i]=c;
        a=b;
        b=c;
    }
}


int main()
{
    int x,n;
    foo();
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        printf("%d\n",foobar[x]);
    }
    return 0;
}
