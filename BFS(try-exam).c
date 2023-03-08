#include<stdio.h>
#include<conio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v)
{
    for(i=0;i<n;i++)
    {
        if(a[v][i] && !visited[i])
        {
            q[++r]=i;
        }
    }
    if(f<=r)
    {
        visited[q[f]]=1;
        bfs(q[f++]);
    }
}
void main()
{
    int v;
    printf("enter the size of the graph :");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        q[i]=0;
        visited[i]=0;
    }
    printf("enter graph data in matrix form :");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the starting vertex :");
    scanf("%d",&v);
    bfs(v);
    printf("the nodes which are reachable are :");
    for(i=0;i<n;i++)
    {
        if(visited[i])
        {
            printf("%d",i);
        }
        else
        {
            printf("bfs not possible ");
        }
    }
    getch();
}


