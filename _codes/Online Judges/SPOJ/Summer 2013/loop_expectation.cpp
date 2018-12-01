#include<iostream>
#include<cstdio>
using namespace std;

double foo[100001];

int main()
{
    foo[1]=1.000000;
    foo[2]=1.500000;
    for(int i=3;i<=100000;i++)
        foo[i]=foo[i-1]+1/i;

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        printf("%.6lf\n",foo[n]);
    }
}
