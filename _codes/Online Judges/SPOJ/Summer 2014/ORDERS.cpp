#include<bits/stdc++.h>
using namespace std;

int ans[200001];
int ctr;

struct node
{
    node *left;
    node *right;

    int data;
    int total_child;
    int height;
};

struct node* newnode(int val)
{
    node *temp=new node();
    temp->left=NULL;
    temp->right=NULL;
    temp->data=val;
    temp->height=1; // Height of Fresh node is 1.
    temp->total_child=1; // Total nodes rooted at this tree including this Node.
    return temp;
}

int getheight(node *x)
{
    if(x==NULL)
        return 0;
    return x->height;
}

int getchild(node *x)
{
    if(x==NULL)
        return 0;
    return x->total_child;
}

struct node* leftRotation(node *x)
{
    node *y =x->right;
    node *z=y->left;

    y->left=x;
    x->right=z;

    x->height=max(getheight(x->left),getheight(x->right))+1;
    x->total_child=(getchild(x->left))+( getchild(x->right))+1;

    y->height=max(getheight(y->left),getheight(y->right))+1;
    y->total_child=(getchild(y->left))+( getchild(y->right))+1;

    return y;
}


struct node* rightRotation(node *x)
{
    node *y =x->left;
    node *z=y->right;

    y->right=x;
    x->left=z;

    x->height=max(getheight(x->left),getheight(x->right))+1;
    x->total_child=(getchild(x->left))+( getchild(x->right))+1;

    y->height=max(getheight(y->left),getheight(y->right))+1;
    y->total_child=(getchild(y->left))+( getchild(y->right))+1;

    return y;
}



struct node* insert(node *x,int val,int moves)
{
    /*
    // In case of a simple BST
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    */
    if(x==NULL)
        return newnode(val);

    if(getchild(x->right)+1>moves)
    {
        x->right= insert(x->right,val,moves);
    }
    else
    {
        moves-=getchild(x->right);
        moves--;
        x->left=insert(x->left,val,moves);
    }

    // update total childs
    x->total_child=(getchild(x->left))+( getchild(x->right))+1;
    // update height
    x->height=max(getheight(x->left),getheight(x->right))+1;
    // get height difference
    int height_diff=getheight(x->left)-getheight(x->right);

    if(height_diff>1)
    {
        int cheight_diff=getheight((x->left)->left)-getheight((x->left)->right);

        //left left
        if(cheight_diff>0)
          return rightRotation(x);

        //left right
        else
        {
            x->left=leftRotation(x->left);
            return  rightRotation(x);
        }
    }
    else if(height_diff<-1)
    {
        int cheight_diff=getheight((x->right)->left)-getheight((x->right)->right);

        //right right
        if(cheight_diff<0)
            return leftRotation(x);
        //right left
        else
        {
            x->right= rightRotation(x->right);
            return leftRotation(x);
        }
    }

    return x;
}

//Inorder Traversal of the Tree
void INORDER(node* x)
{
    if(x==NULL)
        return;
    INORDER(x->left);
    ans[x->data]=ctr++;
    INORDER(x->right);

}
// MAIN
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        node *root=NULL;
        int n,x;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            root=insert(root,i,x);
        }
        ctr=1;
        INORDER(root);
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        printf("\n");
    } // TC
    return 0;
}
