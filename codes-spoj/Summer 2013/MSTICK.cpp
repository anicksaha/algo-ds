#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<fstream>

using namespace std;

vector <int> A(1000000);  // For mimimum
vector <int> B(1000000);  // For maximum
vector <int> a(1000000);

void construct(int node, int begin, int end)
{
     if(begin==end)
     {
        A[node]=a[begin];
        B[node]=a[begin];
     }

     else
     {
        int mid=(begin+end)/2;
        construct(2*node+1, begin, mid);
        construct(2*node+2, mid+1, end);
        A[node]=min(A[2*node+1],A[2*node+2]);
        B[node]=max(B[2*node+1],B[2*node+2]);
     }
}

int queryA(int node, int t_begin, int t_end, int a_begin, int a_end)
{

    if(t_begin>=a_begin && t_end<=a_end)
        return A[node];

    else
    {
        int mid=(t_begin+t_end)/2;

        int res=INT_MAX;

        if(t_begin<=a_end && mid>=a_begin)
            res=min(res, queryA(2*node+1, t_begin, mid, a_begin, a_end));
        if(t_end>=a_begin && (mid+1)<=a_end)
            res=min(res, queryA(2*node+2, mid+1, t_end, a_begin, a_end));

        return res;
    }
}

int queryB(int node, int t_begin, int t_end, int a_begin, int a_end)
{

    if(t_begin>=a_begin && t_end<=a_end)
        return B[node];

    else
    {
        int mid=(t_begin+t_end)/2;

        int res=INT_MIN;

        if(t_begin<=a_end && mid>=a_begin)
            res=max(res, queryB(2*node+1, t_begin, mid, a_begin, a_end));
        if(t_end>=a_begin && (mid+1)<=a_end)
            res=max(res, queryB(2*node+2, mid+1, t_end, a_begin, a_end));

        return res;
    }
}


int main()
{
    //freopen("C:\\Users\\Anick\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\Anick\\Desktop\\out.txt","w",stdout);

    int n;
    scanf("%d",&n);

    //vector <int> a(n+1);

    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);

    //A.resize(4*n+1);
    //B.resize(4*n+1);

    construct(0,0,n-1);

    int q,l,r;
    scanf("%d",&q);

    while(q--)
    {
        scanf("%d%d",&l,&r);
        double ans, foo, bar, nik,temp,temp2;

        foo=queryA(0,0,n-1,l,r);
        bar=queryB(0,0,n-1,l,r);

        nik=0.0;
        temp=0.0;
        if(l!=0)
            nik=queryB(0,0,n-1,0,l-1);
        if(r!=(n-1))
            temp=queryB(0,0,n-1,r+1,n-1);

        //cout<<"Min l-r : "<<foo<<endl;
        //cout<<"Max l-r : "<<bar<<endl;
        //cout<<"Max 0-(l-1) : "<<nik<<endl;
        //cout<<"Max (r+1)-(n-1) : "<<temp<<endl;

        temp=temp+foo;
        nik=nik+foo;
        temp2= foo + (bar-foo)/2;

        ans= max(temp2,max(temp,nik));

        printf("%.1lf\n",ans);
    }

    return 0;
}
