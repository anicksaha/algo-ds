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


int steps(int capacityA,int capacityB,int C)
{
    int steps=0;
    int A=0,B=0,tmp;
    while(A!=C&&B!=C)
    {
        if(A==0)
        {
            A=capacityA;
            steps++;
        }
        else if(B==capacityB)
        {
            B=0;
            steps++;
        }
        else
        {
            tmp=min(capacityB-B,A);
            B+=tmp;
            A-=tmp;
            steps++;
        }
    }
    //cout<<steps<<endl;
    return steps;
}

bool check(int a,int b,int c)
{
    if(c>a && c>b)
        return false;

    if(c%gcd(a,b)!=0)
        return false;

    return true;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        if(!check(a,b,c))
            cout<<"-1"<<endl;

        else if(a==c || b==c)
            cout<<"1"<<endl;

        else
            cout<<min(steps(a,b,c),steps(b,a,c))<<endl;
    }


return 0;
}

