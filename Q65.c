#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int visited[MAX];
int adj[MAX][MAX];
int n;
// DFS function to detect cycle
int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node))
                    return 1;
            }
            else if (i != parent) {
                return 1; // Cycle found
            }
        }
    }
    return 0;
}

int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}