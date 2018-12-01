/* program to construct tree using INORDER and PREORDER traversals */
#include<bits/stdc++.h>
using namespace std;

int IDX;
int Preorder_Index;
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


struct node* buildTree(int INORDER[], int PREORDER[], int inStrt, int inEnd)
{

    if(inStrt>inEnd)
        return NULL;

    struct node *p = newNode(PREORDER[Preorder_Index++]);

    if(inStrt==inEnd)
        return p;


    int idx = search(INORDER, inStrt, inEnd, p->data);

    p->left = buildTree(INORDER, PREORDER, inStrt, idx-1);
    p->right = buildTree(INORDER, PREORDER, idx+1, inEnd);

    return p;
}




void get_post_order(struct node* node)
{
  if (node==NULL)
     return;
  get_post_order(node->left);
  get_post_order(node->right);
  arr[IDX++]=node->data;
}

bool check(int n)
{
    for(int i=1;i<=n;i++)
        if(arr[i]!=POSTORDER[i])
            return false;
    return true;
}

/* Driver program to test above functions */
int main()
{
    Preorder_Index=1;

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        scanf("%d",&PREORDER[i]);

    for(int i=1;i<=n;i++)
        scanf("%d",&POSTORDER[i]);

    for(int i=1;i<=n;i++)
        scanf("%d",&INORDER[i]);

    struct node *root = buildTree(INORDER,PREORDER, 1 ,n);

    IDX=1;
    get_post_order(root);


    if(check(n))
        printf("yes");
    else
        printf("no");

    return 0;
}
