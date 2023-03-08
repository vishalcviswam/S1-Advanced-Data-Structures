#include<stdio.h>
#include<conio.h>

struct BST{
int data;
struct node *left;
struct node *right;
};
typedef struct BST NODE;
NODE*newnode;
NODE*createtree(NODE*newnode,int data)
{
    if(newnode==NULL)
    {
        NODE*temp;
        temp=malloc(sizeof(NODE));
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    if(data<(newnode->data))
    {
        newnode->left=createtree(newnode->left,data);
    }
    else if(data>(newnode->data))
    {
        newnode->right=createtree(newnode->right,data);
    }
    return newnode;
}
void inorder(NODE*newnode)
{
    if(newnode!=NULL)
    {
        inorder(newnode->left);
        printf("%d\t",newnode->data);
        inorder(newnode->right);
    }
}
void preorder(NODE*newnode)
{
    if(newnode!=NULL)
    {
        printf("%d\t",newnode->data);
        preorder(newnode->left);
        preorder(newnode->right);
    }
}
void postorder(NODE*newnode)
{
    if(newnode!=NULL)
    {
        postorder(newnode->left);
        postorder(newnode->right);
        printf("%d\t",newnode->data);
    }
}
void main()
{
    int data,ch,i,n;
    NODE*root=NULL;
    while(1)
    {
    printf("\n 1.Insertion in Binary Tree");
    printf("\n 2.Inorder \n 3.preorder \n 4.postorder");
    printf("\n enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("enter size of the tree :");
        scanf("%d",&n);
        printf("enter tree elements :");
        for(i=0;i<=n;i++)
        {
            scanf("%d",&data);
            root=createtree(root,data);
        }
        break;
    case 2:
        inorder(root);
        break;
    case 3:
        preorder(root);
        break;
    case 4:
        postorder(root);
        break;
    }
    }
}
