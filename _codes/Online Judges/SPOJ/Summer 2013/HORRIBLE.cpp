#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

long long int tree[1000001];
long long int lazy[1000001];
long long int arr[1000001];

void update_tree(int node, int a, int b, int i, int j, int value)
{
  	if(lazy[node] != 0)
    {
   		tree[node] += (long long int)lazy[node]*((b-a)+1);
		if(a!= b)
		{
			lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
		}
   		lazy[node] = 0;
  	}

  	if(a > j || b < i) // Current segment is not within range [i, j]
		return ;

  	if(a >= i && b <= j)
  	{
        tree[node]+= (long long int)value*((b-a)+1);
		if(a != b)
        {
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

		return ;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = tree[node*2]+tree[node*2+1];  // Updating root
}



long long int query_tree(int node, int a, int b, int i, int j)
{
    if(lazy[node] != 0)
    {
   		tree[node] += (long long int)lazy[node]*((b-a)+1);
		if(a!= b)
		{
			lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
		}
   		lazy[node] = 0;
  	}

	if(a > j || b < i) // Current segment is not within range [i, j]
		return 0;

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	long long int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	long long int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	long long int res = q1+q2; // Return final result

	return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);

        for(int i=0;i<=1000000;i++)
        {
        	lazy[i]=0;
        	tree[i]=0;
        }
        while(Q--)
        {
            int q;
            scanf("%d",&q);
            if(q==0)
            {
                int a,b,v;
                scanf("%d%d%d",&a,&b,&v);
                update_tree(1,1,n,a,b,v);

            }
            else if(q==1)
            {
                int l,r;
                scanf("%d%d",&l,&r);
                cout<<query_tree(1,1,n,l,r)<<endl;
            }
        }// Query

    } // tc

    return 0;

}
