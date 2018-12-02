#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

struct node
{
	int one,zero;
	bool lazy;
};

node tree[1000001];

void build_tree(int node, int a, int b)
{
	if(a==b)
	{
		tree[node].lazy=false;
		tree[node].zero=1;
		tree[node].one=0;
		return;
	}
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node].one = tree[node*2].one + tree[node*2+1].one; // Init root value
	tree[node].zero = tree[node*2].zero + tree[node*2+1].zero; // Init root value
	tree[node].lazy=false;
}

void update_tree(int node, int a, int b, int i, int j)
{
  	if(tree[node].lazy)
    {
   		swap(tree[node].one,tree[node].zero);
		if(a!= b)
		{
			tree[node*2].lazy^= true;
            tree[node*2+1].lazy^= true;
		}
   		tree[node].lazy =false;
  	}

  	if(a > j || b < i) // Current segment is not within range [i, j]
		return ;

  	if(a >= i && b <= j)
  	{
        swap(tree[node].one,tree[node].zero);

		if(a != b)
        {
			tree[node*2].lazy ^=true ;
			tree[node*2+1].lazy ^=true ;
		}

		tree[node].lazy=false;
		return ;
	}


	update_tree(node*2, a, (a+b)/2, i, j ); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j); // Updating right child

	tree[node].one = tree[node*2].one +tree[node*2+1].one;  // Updating root
	tree[node].zero = tree[node*2].zero +tree[node*2+1].zero;
}



int query_tree(int node, int a, int b, int i, int j)
{
    if(tree[node].lazy)
    {
   		swap(tree[node].one,tree[node].zero);
		if(a!= b)
		{
			tree[node*2].lazy^= true;
            tree[node*2+1].lazy^= true;
		}
   		tree[node].lazy =false;
  	}

	if(a > j || b < i) // Current segment is not within range [i, j]
		return 0;

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node].one;

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = q1+q2; // Return final result

	return res;
}



int main()
{
    int n,Q;
    scanf("%d%d",&n,&Q);
    build_tree(1,1,n);
    while(Q--)
    {
        int q,a,b;
        scanf("%d%d%d",&q,&a,&b);
        if(q==0)
            update_tree(1,1,n,a,b);
		else
            printf("%d\n",query_tree(1,1,n,a,b));
    }// Query
    return 0;
}
