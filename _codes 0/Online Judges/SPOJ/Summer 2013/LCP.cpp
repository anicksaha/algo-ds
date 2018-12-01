#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char str[1000001];
int s[1000001]; //suffix array
int p[1000001]; // LCP array


int cmp(const void *x,const void *y)
{
    return (strcmp((str+ *((int*)x)),(str+ *((int*)y))));
}
// (qsort) -ve :: true :::: +ve :: false

void suffix_array(long long int l)
{
    int i;
    for(i=0;i<l;i++) s[i]=i;
    qsort(s,l,sizeof(int),cmp);
}

long long lcp(long long int l)
{
    int i, j, k;
    long long count = 0;
    char *z = str, *y = str;

    memset(p,0,sizeof(p));

    for(i=1,k=0;i<l;i++,k=0)
    {
        int temp=0;
        z = str + s[i];
        y = str + s[i-1];
        while(*z==*y)
        {
            p[i]++;
            temp++;
            z++;
            y++;
        }
        count += temp;
    }

    return count;
}

int main()
{
    int t, i, j, c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        long long int len = strlen(str);
        suffix_array(len);
        c = lcp(len);

        for(int i=1;i<len;i++)
            cout<<p[i]<<" ";
        cout<<"\n";
        //cout<<c<<"@"<<endl;
        printf("%lld\n", (len*(len+1)/2)-c);
    }

    return 0;
}
