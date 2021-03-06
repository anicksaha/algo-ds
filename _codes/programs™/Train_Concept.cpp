#include<bits/stdc++.h>
using namespace std;

struct node
{
    long long time;
    int  s; // marker
};


bool comp(node X, node Y)
{
    if(X.time!=Y.time)
        return X.time<Y.time;
    else
        return (X.s<Y.s);
}

/*

int cmp(const void *a,const void *b)
{
    struct node *c=(struct node *)a;
    struct node *d=(struct node *)b;

    if(c->time!=d->time)
        return (c->time-d->time);
    else
        return (c->s-d->s);
}
*/

struct node a[10000009];


int main()
{
    int n,m,l,i,j,k,ans=0;

    int t;
    scanf("%d",&t);

    while(t--)
    {
        cin>>n;
        int  max;
        for(i=0;i<2*n;i+=2)
        {
            scanf("%lld%lld",&a[i].time,&a[i+1].time);
            a[i].s=1;
            a[i+1].s=-1;
        }

        //qsort(a,2*n,sizeof(struct node),cmp);
        sort(a,a+2*n,comp);

        max=a[0].s;
        for(i=1;i<2*n;i++)
        {
            a[i].s+=a[i-1].s;
            if(a[i].s>max)
            max=a[i].s;
        }

        cout<<max<<endl;

    }

return 0;
}
