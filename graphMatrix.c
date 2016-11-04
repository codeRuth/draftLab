// Design, Develop and Implement a Program for the following on Graph (G) of Cities
//	a. Create a Graph of N cities using Adjacency Matrix.
//	b. Print all the nodes reachable from a given starting node in a digraph using BFS method
//	c. Check whether a given graph is connected or not using DFS method.

#include <stdio.h>
#include <stdlib.h>
int a[20][20], q[20], visited[20], reach[10];
int n, i, j, f = 0, r = -1, count = 0, v;

void BFS(int v) {
    for(i = 1; i <= n; i++)
        if(a[v][i] && !visited[i])
            q[++r] = i;
    if(f <= r) {
        visited[q[f]] = 1; BFS(q[f++]);
    }
}

void DFS(int v) {
    int i; reach[v] = 1;
    for(i = 1; i <= n; i++) {
        if(a[v][i] && !reach[i]) {
            printf("%d->%d\n",v,i);
            count++; DFS(i);
        }
    }
}

void createGraph() {
    printf("Enter the Number of Cities: "); scanf("%d",&n);
    for(i = 1; i <= n; i++) {
        q[i] = 0; visited[i] = 0;
    }
    for(i = 1; i <= n-1; i++)
        reach[i] = 0;
    printf("Enter Graph Data in Matrix form:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
}

void main() {
    int choice;
    point:
    printf("1.Create Graph\n2.BFS (Breadth First Search)\n3.DFS (Breadth First Search)\n4.Exit\n");
    printf("Enter your Choice: "); scanf("%d", &choice);
    switch(choice) {
        case 1:
            createGraph(); printf("\nGraph Created.\n");
            goto point;
        case 2:
            printf("Enter the Starting City: "); scanf("%d",&v);
            BFS(v);
            if((v < 1) || (v > n)) { printf("\nBFS is not Possible"); }
            else {
                printf("\nThe Cities which are Reachable from %d : ",v);
                for(i = 1; i <= n; i++)
                    if(visited[i]) printf("%d ", i);
            } printf("\n");
            break;
        case 3:
            DFS(1);
            if(count == n - 1)
                printf("Graph is Connected\n");
            else
                printf("Graph is not Connected\n");
            break;
        case 4: exit(0);
    }
}
