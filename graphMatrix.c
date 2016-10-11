#include <stdio.h>
#include <stdlib.h>
int a[20][20], q[20], visited[20], reach[10];
int n, i, j, f = 0, r = -1, count = 0;

void BFS(int v) {
    for(i = 1; i <= n; i++)
        if(a[v][i] && !visited[i])
            q[++r] = i;
    if(f <= r) {
        visited[q[f]] = 1;
        BFS(q[f++]);
    }
}

void DFS(int v) {
    int i; reach[v] = 1;
    for(i = 1; i <= n; i++) {
        if(a[v][i] && !reach[i]) {
            printf("\n %d->%d",v,i);
            count++; DFS(i);
        }
    }
}

void main() {
    int v, choice;
    printf("Enter the Number of Vertices: "); scanf("%d",&n);
    for(i = 1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }
    for(i = 1; i <= n-1; i++)
        reach[i] = 0;
    printf("Enter Graph Data in Matrix form:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("1.BFS (Breadth First Search)\n2.DFS (Breadth First Search)\n3.Exit\n");
    printf("Enter your Choice: "); scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("\n Enter the Starting Vertex:");
            scanf("%d",&v);
            BFS(v);
            if((v < 1) || (v > n)) {
                printf("\n BFS is not Possible");
            }
            else {
                printf("\n The Nodes which are Reachable from %d:\n",v);
                for(i = 1; i <= n; i++)
                    if(visited[i])
                        printf("%d\t", i);
            }
            break;
        case 2:
            DFS(1);
            if(count == n-1)
                printf("\n Graph is Connected");
            else
                printf("\n Graph is not Connected");
            break;
        case 3: exit(0);
    }
}
