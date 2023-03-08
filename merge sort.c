#include<stdio.h>
int main()
{
int x[50],y[50],a1,a2,s,j,temp1,temp2,temp,k,i; printf("Enter the size of first array:"); scanf("%d",&a1);
printf("Enter the elements of first array:\n"); for(i=0;i<a1;i++){scanf("%d",&x[i]);

printf("\nThe array of first array:\n\t"); for(i=0;i<a1;i++)
{
printf("%d\t",x[i]);
}
temp1=0; for(i=0;i<a1;i++)
{
for(j=i+1;j<a1;j++)
{
if(x[i]>x[j])
{
temp1=x[i]; x[i]=x[j]; x[j]=temp1;
}
}
}
printf("\nThe sorted array of first array:\n\t"); for(i=0;i<a1;i++)
{
printf("%d \t",x[i]);
}
printf("\nEnter the size of second array:"); scanf("%d",&a2);
printf("Enter the elements of second array:\n"); for(j=0;j<a2;j++)
{
scanf("%d",&y[j]);
}
printf("\nThe array of second array:\n\t"); for(j=0;j<a2;j++)
{
printf("%d\t",y[j]);
}


temp2=0; for(i=0;i<a2;i++)
{
for(j=i+1;j<a2;j++)
{
if(y[i]>y[j])
{
temp2=y[i]; y[i]=y[j]; y[j]=temp2;
}
}
}
printf("\nThe sorted array of Second array:\n\t"); for(j=0;j<a2;j++)
{
printf("%d\t",y[j]);
}


s=a2+a1; k=a1;
for(i=0;i<s;i++)
{
x[k]=y[i]; k++;
}
printf("\nThe sorted merge array :\n\t"); for(j=0;j<s;j++)
{
for(i=j+1;i<s;i++)
{
if(x[i]<x[j])
{
temp=x[i]; x[i]=x[j];



x[j]=temp;
}
}
}
for(i=0;i<s;i++)
printf("%d\t",x[i]);
return 0;
}
