#include<stdio.h>
#include<stdlib.h>

void dijkstras(int n, int cost[10][10], int s, int dis[10])
{
    int i,v,count=1,min,visited[10];
    for(i=0;i<=n;i++)
    {
        visited[i] = 0;
        dis[i] = cost[s][i];
    }
    visited[s] = 1;
    dis[s] = 0;

    while(count<=n)
    {
        min = 9999;
        for(i=1;i<=n;i++)
        {
            if(dis[i]<min && visited[i]==0)
            {
                min = dis[i];
                v=i;
            }
            visited[v]=1;
        }
        count++;
        for(i=1;i<=n;i++)
        {
            if(dis[i]>dis[v]+cost[v][i])
            {
                dis[i] = dis[v]+cost[v][i];
            }
        }
    }
}

int main()
{
    int i,j,n,s,cost[10][10],dis[10];

    printf("\nEnter No of Nodes: ");
    scanf("%d",&n);

    printf("\nRead cost matrix\n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            {
                cost[i][j] = 9999;
            }
        }
    }

    printf("\nRead the source node: ");
    scanf("%d",&s);

    dijkstras(n,cost,s,dis);

    printf("\nShortest path from %d is\n",s);
    for(i=1;i<=n;i++)
    {
        if(s!=i)
        {
            printf("%d --> %d = %d\n",s,i,dis[i]);
        }
    }

    return 0;
}
