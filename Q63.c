#include <stdio.h>
#define MAX 100
int visited[MAX];
int adj[MAX][MAX];   // Using adjacency matrix for simplicity
int n;
// DFS function
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("DFS Traversal: ");
    dfs(s);

    return 0;
}