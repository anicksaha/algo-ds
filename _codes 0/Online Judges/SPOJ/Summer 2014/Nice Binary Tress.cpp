#include <cstdio>
#include <algorithm>
#include<cstring>
using namespace std;

char s[100001];

int c;

int dfs()
{
    if(c>=strlen(s))
        return 0;

    if (s[c++] == 'l')
    {
        return 0;
    }

    return max(dfs(), dfs()) + 1;
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        c=0;
        scanf("%s",s);
        printf("%d\n", dfs());
    }

    return 0;
}
