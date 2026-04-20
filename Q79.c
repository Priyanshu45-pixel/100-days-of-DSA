#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 1000

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

// Add edge (undirected)
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->v = u;
    newNode->w = w;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Min distance vertex (simple version instead of heap)
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, idx = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int n, int src) {
    int dist[MAX], visited[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 1; i <= n; i++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;

        visited[u] = 1;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (!visited[v] && dist[u] != INT_MAX &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < MAX; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}