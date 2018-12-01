#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

/*
Sample Input :
4 7
1 0 3
0 1 2
0 1 3
1 0 0
0 0 3
1 3 3
1 0 3

Sample Output :
4
1
0
2
*/

int X,Y,Z;

struct node
{
	int one,zero,two;
	int lazy;
};

node tree[1000001];

void build_tree(int node, int a, int b)
{
	if(a==b)
	{
		tree[node].lazy=0;
		tree[node].zero=1;
		tree[node].one=0;
		tree[node].two=0;
		return;
	}
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node].one = tree[node*2].one + tree[node*2+1].one; // Init root value
	tree[node].zero = tree[node*2].zero + tree[node*2+1].zero; // Init root value
	tree[node].two = tree[node*2].two + tree[node*2+1].two; // Init root value
	tree[node].lazy=0;
}

void update_tree(int node, int a, int b, int i, int j,int value)
{
  	if(tree[node].lazy)
    {
        if(tree[node].lazy%3==1){
            swap(tree[node].zero,tree[node].one);
            swap(tree[node].zero,tree[node].two);
        }
        else if(tree[node].lazy%3==2){
            swap(tree[node].zero,tree[node].one);
            swap(tree[node].one,tree[node].two);
        }

		if(a!= b)
		{
			tree[node*2].lazy+=tree[node].lazy;
            tree[node*2+1].lazy+=tree[node].lazy;
		}
   		tree[node].lazy =0;
  	}

  	if(a > j || b < i) // Current segment is not within range [i, j]
		return ;

  	if(a >= i && b <= j)
  	{

        if(value%3==1)
        {
            swap(tree[node].zero,tree[node].one);
            swap(tree[node].zero,tree[node].two);
        }
        else if(value%3==2)
        {
            swap(tree[node].zero,tree[node].one);
            swap(tree[node].one,tree[node].two);
        }

		if(a!= b)
		{
			tree[node*2].lazy+=value;
            tree[node*2+1].lazy+=value;
		}

		tree[node].lazy=0;
		return ;
	}


	update_tree(node*2, a, (a+b)/2, i, j ,value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j,value); // Updating right child

	tree[node].one = tree[node*2].one +tree[node*2+1].one;  // Updating root
	tree[node].zero = tree[node*2].zero +tree[node*2+1].zero;
	tree[node].two = tree[node*2].two + tree[node*2+1].two;
}



int query_tree(int node, int a, int b, int i, int j)
{
    if(tree[node].lazy)
    {
        if(tree[node].lazy%3==1){
            swap(tree[node].zero,tree[node].one);
            swap(tree[node].zero,tree[node].two);
        }
        else if(tree[node].lazy%3==2){
            swap(tree[node].zero,tree[node].one);
            swap(tree[node].one,tree[node].two);
        }

		if(a!= b)
		{
			tree[node*2].lazy+=tree[node].lazy;
            tree[node*2+1].lazy+=tree[node].lazy;
		}
   		tree[node].lazy =0;
  	}

	if(a > j || b < i) // Current segment is not within range [i, j]
		return 0;

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node].zero;

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
    int c=0;
    while(Q--)
    {
        int q,a,b,val;
        scanf("%d%d%d",&q,&a,&b);
        if(q==0)
            update_tree(1,1,n,a+1,b+1,1);
		else
            printf("%d\n",query_tree(1,1,n,a+1,b+1));
    }// Query
    return 0;
}
