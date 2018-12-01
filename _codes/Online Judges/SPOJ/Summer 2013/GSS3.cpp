// letuskode.blogspot.in/2013/01/segtrees.html :*

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<fstream>

using namespace std;

#define ll int

ll max2(ll a, ll b)
{
    return ((a > b)? a : b);
}

ll max3(ll a, ll b, ll c)
{
    return max2(a, max2(b, c));
}

struct foo
{
    ll sum;
    ll maxv;
    ll lval;  // max prefix sum
    ll rval;  // max suffix sum
};


vector <foo> A(1000000);
vector <ll> a(1000000);

foo combine(foo l,foo r)
{
    foo res;
    res.sum=l.sum+r.sum;
    res.lval=max(l.lval,(l.sum+r.lval));
    res.rval=max(r.rval,(l.rval+r.sum));
    res.maxv=max3(l.maxv,r.maxv,(l.rval+r.lval));

    return res;
}

void constructA(int node, int begin, int end)
{
     if(begin==end)
     {
        A[node].sum=a[begin];
        A[node].maxv=a[begin];
        A[node].lval=a[begin];
        A[node].rval=a[begin];
     }

     else
     {
        int mid=(begin+end)/2;
        constructA(2*node, begin, mid);
        constructA(2*node+1, mid+1, end);

        A[node].sum = A[node*2].sum + A[node*2+1].sum;
        A[node].maxv = max3(A[2*node].maxv,  A[2*node].rval + A[2*node+1].lval,  A[2*node+1].maxv);
        A[node].lval = max2(A[2*node].lval, A[2*node].sum + A[2*node+1].lval);
        A[node].rval = max2(A[2*node].rval + A[2*node+1].sum, A[2*node+1].rval);
     }
}


foo queryA(int node, int t_begin, int t_end, int a_begin, int a_end)
{

    if(t_begin>=a_begin && t_end<=a_end)
        return A[node];

    int mid=(t_begin+t_end)/2;


    foo res;

    if(a_end<=mid)
        res= queryA(2*node, t_begin, mid, a_begin, a_end);
    else if(a_begin>mid)
        res= queryA(2*node+1, mid+1, t_end, a_begin, a_end);
    else
    {
        res=combine (queryA (node*2, t_begin, mid, a_begin, mid),queryA (node*2+1, mid+1, t_end, mid+1, a_end));
    }

    return res;
}




void update(int node, int begin, int end, int pos, int val)
{
     if(begin==end)
     {
        A[node].sum=val;
        A[node].maxv=val;
        A[node].lval=val;
        A[node].rval=val;
     }
     else
     {
        int mid=(begin+end)/2;

        if(pos<=mid)
        {
            update(2*node, begin, mid, pos, val);
        }
        else
        {
            update(2*node+1, mid+1, end, pos, val);
        }

        A[node].sum = A[node*2].sum + A[node*2+1].sum;
        A[node].maxv = max3(A[2*node].maxv,  A[2*node].rval + A[2*node+1].lval,  A[2*node+1].maxv);
        A[node].lval = max2(A[2*node].lval, A[2*node].sum + A[2*node+1].lval);
        A[node].rval = max2(A[2*node].rval + A[2*node+1].sum, A[2*node+1].rval);
     }
}



int main()
{
    //freopen("C:\\Users\\Anick\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\Anick\\Desktop\\out.txt","w",stdout);

    int n;
    scanf("%d",&n);

    //vector <int> a(n+1);

    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);

    //A.resize(4*n+1);
    //B.resize(4*n+1);

    constructA(1,1,n);

    int q,l,r,type;
    scanf("%d",&q);

    while(q--)
    {
        scanf("%d%d%d",&type,&l,&r);
        if(type==1)
            printf("%d\n",queryA(1,1,n,l,r).maxv);
        else
            update(1,1,n,l,r);
    }

    return 0;
}

