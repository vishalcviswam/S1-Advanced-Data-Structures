#include<stdio.h>
#include<conio.h>

int a[20],b[20],c[20],x,i,j;

void set_union(int a[],int b[],int m)
{
    for(i=0;i<m;i++)
    {
        c[i]=a[i] || b[i];
        printf("%d \t",c[i]);
    }
}
void set_intersection(int a[],int b[],int m)
{
    for(i=0;i<m;i++)
    {
        c[i]=a[i] && b[i];
        printf("%d \t",c[i]);
    }
}void set_difference(int a[],int b[],int m)
{
    for(i=0;i<m;i++)
    {
        c[i]=!b[i] && a[i];
        printf("%d \t",c[i]);
    }
}



void main()
{
    int m,n,p;
    printf("enter the size of first set :");
    scanf("%d",&m);
    printf("enter the size of second set :");
    scanf("%d",&n);
    printf("enter first array elements :");
    for(i=0;i<m;i++)
    {
        main:scanf("%d",&p);
        if(p==0 || p==1)
        {
            a[i]=p;
        }
        else
        {
            printf("set only accept zeros and ones ");
            goto main;
        }
    }
    printf("enter second array elements :");
    for(i=0;i<n;i++)
    {
        main1:scanf("%d",&p);
        if(p==0 || p==1)
        {
            b[i]=p;
        }
        else
        {
            printf("set only accept zeros and ones ");
            goto main1;
        }
    }
    while(1)
    {
        printf("MAIN MENU\n");
        printf("\n1.union   \n2.intersection  \n3.difference");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            if(m==n)
            {
                set_union(a,b,m);

            }
            else
            {
                printf("different size");
            }
         case 2:
            if(m==n)
            {
                set_intersection(a,b,m);

            }
            else
            {
                printf("different size");
            }
         case 3:
            if(m==n)
            {
                set_difference(a,b,m);

            }
            else
            {
                printf("different size");
            }
        }
    }
}
