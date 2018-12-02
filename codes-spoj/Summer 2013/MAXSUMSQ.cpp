#include<iostream>
#include<cstdio>
#include<algorithm>
#include<fstream>

using namespace std;

int a[1000000];
long long int nik[1000000];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            cin>>a[i];

        nik[1]= a[1]>=0 ? a[1]:0;

        for(int i=2;i<=n;i++)
        {
            nik[i]= a[i]>=0 ? (nik[i-1]+a[i]):nik[i-1];
        }
        for(int i=1;i<=n;i++)
            cout<<nik[i]<<" ";


    }

    return 0;

}
