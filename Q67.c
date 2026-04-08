#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node {
    int data;
    struct Node* next;
};
struct Node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(temp->data);
        }
        temp = temp->next;
    }

    // Push to stack
    stack[++top] = v;
}

// Topological sort
void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Main function
int main() {
    int V = 6;

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Example DAG
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topologicalSort(V);

    return 0;
}