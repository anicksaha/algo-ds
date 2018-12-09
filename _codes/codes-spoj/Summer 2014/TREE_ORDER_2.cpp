/* program to construct tree using INORDER and PostORDER traversals */

/*
            1
        2      3
      4   5   8
         6 7

    INORDER : 4 2 6 5 7 1 8 3
    PRE     : 1 2 4 5 6 7 3 8
    POST    : 4 5 7 5 2 8 3 1
*/
#include<bits/stdc++.h>
using namespace std;

int IDX;

int PREORDER[8010];
int POSTORDER[8010];
int INORDER[8010];

int arr[8010];

struct node
{
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int data)
{
  struct node* p= (struct node*)malloc(sizeof(struct node));
  p->data = data;
  p->left = NULL;
  p->right = NULL;

  return(p);
}


int search(int arr[], int start, int end, int value)
{
  for(int i = start; i<=end;i++)
    if(arr[i] == value)
      return i;
}


struct node* buildTree(int INORDER[], int POSTORDER[], int instart, int inend, int poststart, int postend)
{

    if(instart>inend)
        return NULL;

    struct node *p = newNode(POSTORDER[postend]);

    if(instart==inend)
        return p;


    int idx = search(INORDER, instart, inend, p->data);

    p->left = buildTree(INORDER, POSTORDER, instart, idx-1,  poststart,  poststart + (idx-instart)-1 );
    p->right = buildTree(INORDER, POSTORDER, idx+1, inend,  poststart + (idx-instart) , postend-1); //

    return p;
}




void get_pre_order(struct node* node)
{
  if (node==NULL)
     return;

  arr[IDX++]=node->data;
  get_pre_order(node->left);
  get_pre_order(node->right);

}

bool check(int n)
{
    for(int i=1;i<=n;i++)
        if(arr[i]!=PREORDER[i])
            return false;
    return true;
}

/* Driver program to test above functions */
int main()
{

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        scanf("%d",&PREORDER[i]);

    for(int i=1;i<=n;i++)
        scanf("%d",&POSTORDER[i]);

    for(int i=1;i<=n;i++)
        scanf("%d",&INORDER[i]);


    struct node *root = buildTree(INORDER,POSTORDER, 1 ,n,1,n);  // from INORDER and POSTORDER

    IDX=1;
    get_pre_order(root);


    if(check(n))
        printf("yes");
    else
        printf("no");

    return 0;
}
