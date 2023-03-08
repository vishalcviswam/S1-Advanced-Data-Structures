#include<stdio.h>
#include<conio.h>
int a[20][20],reach[20],n,i,j;

void main()
{
    int count=0;
    printf("enter the size of the graph :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        reach[i]=0;
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    printf("enter the values in matrix form :");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    dfs(1);
    printf("\n");
    for(i=1;i<n;i++)
    {
        if(reach[i])
        {
            count++;
        }
    }
    if(count==n)
    {
        printf("graph is connected ");
    }
    else
    {
        printf("graph is not connected");
    }
}
void dfs(int v)
{
    reach[v]=1;
    for(i=1;i<n;i++)
    {
        if(a[v][i] && !reach[i])
        {
            printf("%d->%d\n",v,i);
        }
    }
    dfs(i);
}
