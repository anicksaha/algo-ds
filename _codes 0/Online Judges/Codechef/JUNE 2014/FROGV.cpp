#include<bits/stdc++.h>
using namespace std;

struct node
{
    int id,pos,backjump;
};

node arr[100001];

bool comp(node X,node Y)
{
    if(X.pos<Y.pos)
        return true;
    return false;
}

int main()
{
    int n,q,k;

    int a,b;
    map<int,int> HASH; // ID -> Index

    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)
        cin>>arr[i].pos,arr[i].id=i;

    sort(arr+1,arr+n+1,comp);

    /*
    for(int i=1;i<=n;i++)
        cout<<arr[i].id<<" "<<arr[i].pos<<endl;
    cout<<endl;
    */

    for(int i=1;i<=n;i++)
        HASH[arr[i].id]=i;


    arr[1].backjump=0;

    int ctr=0;


    for(int i=2;i<=n;i++)
    {
        if(arr[i].pos<=arr[i-1].pos+k)
        {
            ctr++;
            arr[i].backjump=ctr;
        }
        else
        {
            ctr=0;
            arr[i].backjump=ctr;
        }
    }

    /*
    for(int i=1;i<=n;i++)
        cout<<arr[i].id<<" "<<arr[i].backjump<<endl;
    cout<<endl;
    */

    while(q--)
    {
        cin>>a>>b;

        int idx1,idx2;

        idx1=HASH[a];
        idx2=HASH[b];


        if(idx2<idx1)
            swap(idx1,idx2);

        //cout<<idx1<<" & "<<idx2<<endl;

        //cout<<arr[idx1].backjump<<"  "<<arr[idx2].backjump<<endl;

        if((idx2-arr[idx2].backjump)<=idx1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

	return 0;
}
