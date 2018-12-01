//http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int maxVal;//the maximum index or value with non-zero frequency
vector <int> tree;// contains the sum of frequencies responsible; responsible frequency range is idx-2^r+1 to idx where r is the position of last one in 
                   // binary representation of idx  

int read(int idx){//this function returns the cumulative frequency of the index idx
    int sum=0;
    while(idx>0){
                 sum+=tree[idx];
                 idx-=(idx & -idx);//method to get the last non zero digit in binary representation
                 }
    return sum;
}

void update(int idx, int val){//this function updates the frequencies by updating the tree sum frequencies
     while(idx<=maxVal){
                        tree[idx]+=val;
                        idx+=(idx & -idx);//reverse process of the above
                        }
     }

int main(){
    int n;
    scanf("%d",&n);//size of the tree
    maxVal=n;
    tree.resize(n+1,0);
    while(1){
             int query;
             scanf("%d",&query);
             if(query==1){
                          int i;
                          scanf("%d",&i);
                          cout<<read(i)<<endl;
                          }
             else if(query==2){
                  int i,v;
                  scanf("%d%d",&i,&v);
                  update(i,v);
                  }
             else
                 break;
             }
    return 0;
}
                       
    
