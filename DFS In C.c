#include<stdio.h>
#define N 11
int vis[N],adj[N][N],stack[N];
int top=-1;
void push(int n)
{
    if(top>=N)
        printf("stack is overflw:\n");
    else
        stack[++top]=n;

}
int pop()
{

    if(top<0)
    {
        return 0;
    }
    else
        return stack[top--];

}
void dfs(int s,int n)
{
    int p,i,j;
    push(s);
    vis[s]=1;
    p=pop();
    printf(" result= %d",p);
    while(p!=0)
    {
        for(i=1; i<=n; i++)
        {
            if(adj[p][i]!=0 && vis[i]==0)
            {
                push(i);
                vis[i]=1;
            }
        }
        p=pop();
        if(p!=0)
            printf(" %d",p);
    }
}
int main()
{
    int i,j,n,s;
    printf("How many vertex:\n");
    scanf("%d",&n);
    printf("Enter adj matrix:\n");
    printf("\n");
    for(i=1; i<=n; i++)
    {
        vis[i]=0;
        for(j=1; j<=n; j++)
        {
            printf("  %d is connected to %d :\n",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Adj matix:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf(" %d",adj[i][j]);
        }
        printf("\n");
    }
    printf("Enter the source vertex:\n");
    scanf("%d",&s);
    dfs(s,n);

}