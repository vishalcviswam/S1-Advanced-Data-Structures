#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void push();
void pop();
void display();

struct node
{
    int data;
    struct node*next;
};
struct node *top;
void main()
{
    int choice=0;
    while(choice !=4)
    {
        printf("\nMain menu\n");
        printf("\n1.Insert,\n2.Delete,\n3.Display");
        printf("\nchoose one form the following\n");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            printf("\nenter a valid option");
    }
}
}
void push()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int item;
    if(newnode==NULL){
        printf("\nnot able to isert");
    }
    else
    {
        printf("\nenter the value :");
        scanf("%d",&item);
    }
    if(top==NULL)
    {
        newnode->data=item;
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        newnode->data=item;
        newnode->next=top;
        top=newnode;
    }
    printf("\nitem pushed");
}
void pop()
{
   struct node *newnode;
   int item;
   if(top==NULL)
   {
       printf("underflow");

   }
   else{
        item=top->data;
        newnode=top;
        top=top->next;
        free(newnode);
        printf("item popped");
    }
}
void display()
{
    struct node *newnode;
    newnode = top;
    if(newnode == NULL)
    {
        printf("the list is empty");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (newnode!=NULL)
        {
            printf("\n%d",newnode->data);
            newnode = newnode -> next;
        }
    }
}
