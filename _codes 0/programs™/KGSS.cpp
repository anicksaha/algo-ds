#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<fstream>

using namespace std;

vector <pair <int, int> > A;
vector <int> a;

void construct(int node, int begin, int end)
{
     if(begin==end)
        A[node]=make_pair(a[begin], -1);
     else
     {

         int mid=(begin+end)/2;
         construct(2*node, begin, mid);
         construct(2*node+1, mid+1, end);
         int aa,b;
         if(A[2*node].first>A[2*node+1].first)
         {
            aa=A[2*node].first;
            b=max(A[2*node].second, A[2*node+1].first);
         }
         else
         {
            aa=A[2*node+1].first;
            b=max(A[2*node+1].second, A[2*node].first);
         }

         A[node]=make_pair(aa,b);
      }
}

void update(int node, int begin, int end, int pos, int val)
{
     if(begin==end)
        A[node]=make_pair(val, -1);
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


        int aa,b;
        if(A[2*node].first>A[2*node+1].first)
        {
            aa=A[2*node].first;
            b=max(A[2*node].second, A[2*node+1].first);
        }
        else
        {
            aa=A[2*node+1].first;
            b=max(A[2*node+1].second, A[2*node].first);
        }

         A[node]=make_pair(aa,b);
     }
}

pair <int, int> query(int node, int t_begin, int t_end, int a_begin, int a_end){
    if(t_begin>=a_begin && t_end<=a_end)
                        return A[node];
    else{
         int mid=(t_begin+t_end)/2;
         pair <int, int> p=make_pair(-1, -1);
         pair <int, int> temp;
         if(t_begin<=a_end && mid>=a_begin){
                           temp=query(2*node, t_begin, mid, a_begin, a_end);
                           int aa,b;
                           if(p.first>temp.first){
                                aa=p.first;
                                b=max(p.second, temp.first);
                           }
                           else{
                                aa=temp.first;
                                b=max(p.first, temp.second);
                           }
                           p=make_pair(aa,b);
                        }
         if(t_end>=a_begin && (mid+1)<=a_end){
              temp=(query(2*node+1, mid+1, t_end, a_begin, a_end));
              int aa,b;
              if(p.first>temp.first){
                                aa=p.first;
                                b=max(p.second, temp.first);
                           }
              else{
                                aa=temp.first;
                                b=max(p.first, temp.second);
                           }
              p=make_pair(aa,b);
         }
         return p;
         }
}


int main(){
    int n;
    scanf("%d",&n);
    a.resize(n+1);
    for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
    A.resize(4*n+1);
    construct(1,1,n);
    int Q;
    scanf("%d", &Q);
    while(Q--){
             char q;
             cin>>q;
             if(q==(int)'U'){
                          int p,v;
                          scanf("%d%d",&p,&v);
                          update(1,1,n,p,v);
                          }
             else if(q==(int)'Q'){
                  int l,r;
                  scanf("%d%d",&l,&r);
                  pair <int, int> mypair=query(1,1,n,l,r);
                  printf("%d\n", mypair.first+mypair.second);
                  }
             }
    return 0;
}
