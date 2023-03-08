#include<stdio.h>
#include<conio.h>
int count=0;
struct node
{
int data;
struct node *prev;
struct node *next;
};
struct node *head=NULL;
struct node *temp=NULL;
int item;
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void display();

void main()
{
int opt,item;
while(opt!=9)
{
printf("\n SELECT A VALID OPTION FROM THE MENU\n");
printf("\n1. INSERTION AT BEGINNING\n");
printf("\n2. INSERTION AT END\n");
printf("\n3. INSERTION AT A GIVEN POSITION\n");
printf("\n4. DELETION AT BEGINNING\n");
printf("\n5. DELETION AT END\n");
printf("\n6. DELETION AT A PARTICULAR POSITION\n");
printf("\n7. DISPLAY LIST\n");
printf("\n8. EXIT\n");
scanf("%d",&opt);
switch(opt)
{
case 1: insert_begin();
break;
case 2: insert_end();
break;
case 3: insert_pos();
break;
case 4: delete_begin();
break;
case 5: delete_end();
break;
case 6: delete_pos();
break;
case 7: display();
break;
case 8: exit(0);
default: printf("\n Invalid Option\n");
}
}
}
void insert_begin()
{
    struct node*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter value :");
    scanf("%d",&item);
    newnode->data=item;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
        head->prev=newnode;
        count++;
    }
    else
    {
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
        head->prev=newnode;
        count++;
    }
    printf("node inserted");
}
void insert_end()
{
    struct node*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data :");
    scanf("%d",&item);
    newnode->data=item;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
        head->prev=newnode;
        count++;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
        count++;
    }
}
void insert_pos()
{
    int loc,i;
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data :");
    scanf("%d",&item);
    newnode->data=item;
    printf("enter location :");
    scanf("%d",&loc);
    temp=head;
    for(i=0;i<loc;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->prev=temp;

    printf("node inserted ");
}

void delete_begin()
{
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=head;
        head=temp->next;
        free(temp);
    }
    printf("node deleted");
}

void delete_end()
{
    struct node*prevv;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=head;
        while(temp->next !=NULL)
        {
            prevv=temp;
            temp=temp->next;
        }
        prevv->next=NULL;
        free(temp);
        printf("node deleted");
    }
}

void delete_pos()
{
    int loc,i;
    struct node*prevv;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        printf("enter location :");
        scanf("%d",&loc);
        temp=head;
        for(i=0;i<loc;i++)
        {
            prevv=temp;
            temp=temp->next;
        }
        prevv->next=temp->next;
        temp->next->prev=prevv;
        free(temp);
        printf("node deleted");

    }
}
void display()
{
    temp=head;
   while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
