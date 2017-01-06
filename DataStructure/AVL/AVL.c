#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value, height;
    struct node* left;
    struct node* right;
}node;
node* rotate(node* before, node* after)
{
    if(before->left==after)
    {
        before->left=after->right;
        after->right=before;
    }
    else
    {
        before->right=after->left;
        after->left=before;
    }
    before->height=height(before->left)>height(before->right)?height(before->left)+1:height(before->right)+1;
    after->height=height(after->left)>height(after->right)?height(after->left)+1:height(after->right)+1;
    return after;
}
int height(node* cur)
{
    if(cur==NULL)
        return -1;
    return cur->height;
}
node* insert(node* cur, int inp)
{
    //Construct a normal BST
    if(cur==NULL)
    {
        node* New=(struct node*)malloc(sizeof(node));
        New->value=inp;
        New->height=0;
        New->left=NULL;
        New->right=NULL;
        return New;
    }
    else if(inp<cur->value)
    {
        cur->left=insert(cur->left, inp);
    }
    else
    {
        cur->right=insert(cur->right, inp);
    }
    //Update height;
    int lh=height(cur->left);
    int rh=height(cur->right);
    cur->height=lh>rh?lh+1:rh+1;
    //Rotation
    if(lh-rh>1 && inp<cur->left->value)
    {
        return rotate(cur, cur->left);
    }
    else if(rh-lh>1 && inp>cur->right->value)
    {
        return rotate(cur, cur->right);
    }
    else if(lh-rh>1)
    {
        cur->left=rotate(cur->left, cur->left->right);
        return rotate(cur, cur->left);
    }
    else if(rh-lh>1)
    {
        cur->right=rotate(cur->right, cur->right->left);
        return rotate(cur, cur->right);
    }
    return cur;
}
int cnt=0,total=0;
void infix(node* cur)
{
    if(cur==NULL)
        return;
    infix(cur->left);
    ++cnt;
    printf("%d", cur->value);
    if(total!=cnt)
        printf(",");
    infix(cur->right);
    return;
}
void postfix(node* cur)
{
    if(cur==NULL)
        return;
    postfix(cur->left);
    postfix(cur->right);
    ++cnt;
    printf("%d", cur->value);
    if(total!=cnt)
        printf(",");
    return;
}
int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int inp;
        node* Tree=NULL;
        total=0;
        while(scanf("%d", &inp)==1)
        {
            if(inp==-1)
                break;
            ++total;
            Tree=insert(Tree, inp);
        }
        cnt=0;
        infix(Tree);
        printf("\n");
        cnt=0;
        postfix(Tree);
        printf("\n");
    }
    return 0;
}
