#include<stdio.h>
#include<conio.h>
struct node{
    int data;
struct node*next;
};
struct node *head ,*temp,*prev;

struct firstnode{
    int data;
struct node*next;
};
struct firstnode *headf ,*tempf,*prevf;

struct secondnode{
    int data;
struct node*next;
};
struct secondnode *heads ,*temps,*prevs;


int item;
void beg_Insert();
void last_Insert();
void random_Insert();
void begin_Delete();
void last_Delete();
void random_delete();
void create();
void display();
void display();
void main()
{
    int choice=0;
    while(1)
    {
        printf("\nchoose one from following list\n");
        printf("\n MAIN MENU\n");
        printf("\n1.insert in beginning \n2.insert in last \n3.Insert randomly \n4.Delete at Beginning \n5.Delete at last \n6.Delete Randomly \n7.Display \n8.Sort");
        printf("\nenter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            beg_Insert();
            break;
        case 2:
            last_Insert();
            break;
        case 3:
            random_Insert();
            break;
        case 4:
            begin_Delete();
            break;
        case 5:
            last_Delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            display();
            break;
        case 8:
            sort();
            break;
        }
    }
}
void beg_Insert()
{
    struct firstnode*first;
    struct secondnode*second;
    first=(struct firstnode*)malloc(sizeof(struct firstnode));
    second=(struct secondnode*)malloc(sizeof(struct secondnode));

    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the value :");
    scanf("%d",&item);
    newnode->data=item;

    if(item%2==0)
    {
        first->data=item;
        if(headf==NULL)
            {
        headf=first;
        first->next=NULL;
            }
        else
            {
        first->next=headf;
        headf=first;
            }
    }
    else
    {
        second->data=item;
        if(heads==NULL)
            {
        heads=second;
        second->next=NULL;
            }
        else
            {
        second->next=heads;
        heads=second;
            }
    }

    //main
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=head;
        head=newnode;
    }

    printf("node inserted");
}
void last_Insert()
{
    struct firstnode*first;
    struct secondnode*second;
    first=(struct firstnode*)malloc(sizeof(struct firstnode));
    second=(struct secondnode*)malloc(sizeof(struct secondnode));

    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter value:");
    scanf("%d",&item);
    newnode->data=item;
    if(item%2==0)
    {
        first->data=item;
        if(headf==NULL)
    {
        headf=first;
        first->next=NULL;
    }
    else
    {
        tempf=headf;
        while(tempf->next!=NULL)
        {
            tempf=tempf->next;
        }
        tempf->next=first;
        first->next=NULL;
    }
    }
    else
    {
        second->data=item;
        if(heads==NULL)
    {
        heads=second;
        second->next=NULL;
    }
    else
    {
        temps=heads;
        while(temps->next!=NULL)
        {
            temps=temps->next;
        }
        temps->next=second;
        second->next=NULL;
    }
    }

    //main
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
    printf("node inserted");
}
void random_Insert()
{
    int loc,i;
    struct node*newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter value: ");
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
    printf("node inserted");
}
void begin_Delete()
{
    if(head==NULL)
    {
        printf("\nthe list is empty\n");
    }
    else{
        temp=head;
        head=temp->next;
        free(temp);
        printf("node deletd");
    }
}
void last_Delete()
{
    temp=head;
    while(temp->next !=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;;
    free(temp);
    printf("node deleted");
}
void random_delete()
{
    int loc,i;
    printf("\n enter location :");
    scanf("%d",&loc);
    temp=head;
    for(i=0;i<loc;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    printf("node deletd");
}

void sort()
{
    tempf=headf;
    printf("\neven nodes :");
    while(tempf!=NULL)
    {
        printf("%d \t",tempf->data);
        tempf=tempf->next;
    }
    temps=heads;
    printf("\nodd nodes :");
    while(temps!=NULL)
    {
        printf("%d \t",temps->data);
        temps=temps->next;
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d \t",temp->data);
        temp=temp->next;
    }
}

