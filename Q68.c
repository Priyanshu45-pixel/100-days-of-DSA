#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Queue implementation
int queue[MAX], front = -1, rear = -1;
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Topological Sort using Kahn's Algorithm
void topologicalSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int i, j;

    // Step 1: Calculate in-degree
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Step 2: Enqueue vertices with in-degree 0
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;
    int topo[MAX];

    // Step 3: Process queue
    while (front <= rear) {
        int u = dequeue();
        topo[count++] = u;

        for (i = 0; i < n; i++) {
            if (adj[u][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // Step 4: Check for cycle
    if (count != n) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }

    // Print result
    printf("Topological Order: ");
    for (i = 0; i < n; i++)
        printf("%d ", topo[i]);
    printf("\n");
}

int main() {
    int n, i, j;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(n, adj);

    return 0;
}