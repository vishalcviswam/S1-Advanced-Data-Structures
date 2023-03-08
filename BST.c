#include<stdio.h>
#include<stdlib.h>
struct BST
{
    int data;
    struct BST*left;
    struct BST*right;
};
typedef struct BST NODE;
NODE*node;
NODE*createtree(NODE*node,int data)
{
 if(node==NULL)
{
    NODE*temp;
    temp=malloc(sizeof(NODE));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
if(data<(node->data))
{
    node->left=createtree(node->left,data);
}
else if(data>node->data)
{
    node->right=createtree(node->right,data);
}
return node;
}
NODE*search(NODE*node,int data)
{
    if(node==NULL)
    {
        printf("\n element is not found");
    }
    else if(data<node->data)
    {
        node->left=search(node->left,data);
    }
    else if(data<node->data)
    {
        node->right=search(node->right,data);
    }
    else
    {
        printf("\n element found in %d",node->data);
        return node;
    }
}
void inorder(NODE*node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d\t",node->data);
        inorder(node->right);
    }
}
void preorder(NODE*node)
{
    if(node!=NULL)
    {
        printf("%d\t",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(NODE*node)
{
    if(node!=NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t",node->data);
    }
}
NODE*findMin(NODE*node)
{
    if(node==NULL)
    {
      return NULL;
    }
    if(node->left)
    return findMin(node->left);
    else
    return node;
}
NODE *del(NODE*node,int data)
{
    NODE*temp;
    if(node==NULL)
    {
        printf("\n element not found");
    }
    else if(data<node->data)
    {
        node->left=del(node->left,data);
    }
    else if(data>node->data)
    {
       node->right=del(node->left,data);
    }
    else
    {
        if(node->right&&node->left)
        {
            temp=findMin(node->right);
            node->data=temp->data;
            node->right=del(node->right,temp->data);
        }
        else
        {
            temp=node;
            if(node->left==NULL)
            {
                node=node->right;
            }
            else if(node->right==NULL)
            {
                node=node->left;
            }
            free(temp);

        }
    }
return node;
}
int main()
{
int data,ch,i,n;
NODE*root=NULL;
while(1)
{
    printf("\n 1.Insertion in Binary Tree");
    printf("\n 2.Search element in BST");
    printf("\n 3.delete element in BST");
    printf("\n 4.Inorder \n 5.preorder \n 6.postorder");
    printf("\n 7.findmin");
    printf("\n enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("\n enter the size:");
        scanf("%d",&n);
        printf("\n enter the elements to create a BST:");
        for(i=0;i<n;i++)
        {
            scanf("%d",&data);
            root=createtree(root,data);
        }
        break;
    case 2:
        printf("\n enter the element to search:");
        scanf("%d",&data);
        root=search(root,data);
        break;
    case 3:
        printf("\n enter the element to delete:");
        scanf("%d",&data);
        root=del(root,data);
        break;
    case 4:
        printf("Inorder Traversal:");
        inorder(root);
        break;
    case 5:
        printf("Preorder Traversal:");
        preorder(root);
        break;
    case 6:
        printf("Postorder Traversal:");
        postorder(root);
        break;
    case 7:
        findMin(root);
        break;
    default:
        printf("\n wrong option");
        break;
    }
}
return 0;
}
