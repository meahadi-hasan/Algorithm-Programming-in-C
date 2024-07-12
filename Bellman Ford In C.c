#include<stdio.h>
#include<stdlib.h>

void bellmanFord(int n, int cost[10][10], int s, int dis[10]) {
    int i, j, k;

    for(i = 1; i <= n; i++) {
        dis[i] = 9999;
    }
    dis[s] = 0;

    for(k = 1; k <= n - 1; k++) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(cost[i][j] != 9999 && dis[j] > dis[i] + cost[i][j]) {
                    dis[j] = dis[i] + cost[i][j];
                }
            }
        }
    }
}

int main() {
    int i, j, n, s, cost[10][10], dis[10];

    printf("\nEnter No of Nodes: ");
    scanf("%d", &n);

    printf("\nRead cost matrix\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) {
                cost[i][j] = 9999;
            }
        }
    }

    printf("\nRead the source node: ");
    scanf("%d", &s);

    bellmanFord(n, cost, s, dis);

    printf("\nShortest path from %d is\n", s);
    for(i = 1; i <= n; i++) {
        if(s != i) {
            printf("%d --> %d = %d\n", s, i, dis[i]);
        }
    }

    return 0;
}
