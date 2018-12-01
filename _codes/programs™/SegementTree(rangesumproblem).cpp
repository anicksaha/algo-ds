//http://wcipeg.com/wiki/Segment_tree

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector <int> A;

void construct(int node, int begin, int end, vector <int> a){
     if(begin==end)
                   A[node]=a[begin];
     else{
          int mid=(begin+end)/2;
          construct(2*node, begin, mid, a);
          construct(2*node+1, mid+1, end, a);
          A[node]=A[2*node]+A[2*node+1];
          }
     }

void update(int node, int begin, int end, int pos, int val){
     if(begin==end)
                   A[node]=val;
     else{
          int mid=(begin+end)/2;
          if(pos<=mid){
                       update(2*node, begin, mid, pos, val);
                       }
          else{
               update(2*node+1, mid+1, end, pos, val);
               }
          A[node]=A[2*node]+A[2*node+1];
          }
     }
     
int query(int node, int t_begin, int t_end, int a_begin, int a_end){
    if(t_begin>=a_begin && t_end<=a_end)
                        return A[node];
    else{
         int mid=(t_begin+t_end)/2;
         int res=0;
         if(t_begin<=a_end && mid>=a_begin)
                           res+=query(2*node, t_begin, mid, a_begin, a_end);
         if(t_end>=a_begin && (mid+1)<=a_end)
              res+=(query(2*node+1, mid+1, t_end, a_begin, a_end));
         return res;
         }
}
    

int main(){
    int n;
    scanf("%d",&n);
    vector <int> a(n+1);
    for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
    A.resize(4*n+1);
    construct(1,1,n,a);
    for(int i=1;i<=4*n;++i){
            cout<<A[i]<<" ";
            }
    cout<<endl;
    while(1){
             int q;
             scanf("%d",&q);
             if(q==1){
                          int p,v;
                          scanf("%d%d",&p,&v);
                          update(1,1,n,p,v);
                          }
             else if(q==2){
                  int l,r;
                  scanf("%d%d",&l,&r);
                  cout<<query(1,1,n,l,r)<<endl;
                  }
             else
                 break;
             }
    return 0;
}
