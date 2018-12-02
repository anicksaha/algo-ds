#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[1000001];
int s[1000001];  // suffix_array


int cmp(const void *x,const void *y)
{
    return (strcmp((str+ *((int*)x)),(str+ *((int*)y))));
}
// (qsort) -ve :: true :::: +ve :: false

void suffix_array(int n)
{
    int i;
    for(i=0;i<n;i++) s[i]=i;
    qsort(s,n,sizeof(int),cmp);
}

int main()
{
    int n, i, j, c;
    //scanf("%d",&n);
    //while(n--)
    //{
        scanf("%s",str);
        int l = strlen(str);
        //cout<<(str+2)<<endl; str=banana$ (str+2) -> nana$
        suffix_array(l);
        for(i=0;i<l;i++) cout<<s[i]<<" ";

    //}
    return 0;
}
