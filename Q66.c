#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};
struct Node* adj[MAX];
int visited[MAX];
int recStack[MAX];
// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (directed)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function to detect cycle
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int neighbor = temp->data;

        // If not visited → DFS
        if (!visited[neighbor]) {
            if (dfs(neighbor))
                return 1;
        }
        // If in recursion stack → cycle found
        else if (recStack[neighbor]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
}

// Function to check cycle
int hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

// Main
int main() {
    int V = 4;

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    // Example graph
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 1);  // Cycle here

    if (hasCycle(V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}