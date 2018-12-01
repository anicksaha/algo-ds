#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

int table[2][5005];

int LCS(char *a)
{
int i,j,k,l=strlen(a);
    for(i=l-1;i>=0;i--)
    {
        for(j=0;j<l;j++)
        {
            if(a[i]==a[j])
            table[1][j+1]=table[0][j]+1;
            else table[1][j+1]=max(table[1][j],table[0][j+1]);
        }
        for(k=0;k<=l;k++)
        table[0][k]=table[1][k];
    }
    return table[1][j];
}


int main()
{
    char a[5005];
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    printf("%d\n",n-LCS(a));

    return 0;
}
