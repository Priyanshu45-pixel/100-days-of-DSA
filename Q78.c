#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 1005

typedef struct {
    int to, weight;
} Edge;

Edge adj[MAX][MAX];
int adjSize[MAX];

typedef struct {
    int node, weight;
} HeapNode;

HeapNode heap[MAX * MAX];
int heapSize = 0;

// Swap two heap nodes
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Push into min-heap
void push(int node, int weight) {
    heap[++heapSize].node = node;
    heap[heapSize].weight = weight;

    int i = heapSize;
    while (i > 1 && heap[i].weight < heap[i / 2].weight) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

// Pop minimum element
HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= heapSize && heap[left].weight < heap[smallest].weight)
            smallest = left;
        if (right <= heapSize && heap[right].weight < heap[smallest].weight)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }

    return top;
}

// Prim’s Algorithm
int prim(int n) {
    bool visited[MAX] = {false};
    int totalWeight = 0;

    push(1, 0);  // start from node 1

    while (heapSize > 0) {
        HeapNode current = pop();
        int node = current.node;
        int weight = current.weight;

        if (visited[node]) continue;

        visited[node] = true;
        totalWeight += weight;

        for (int i = 0; i < adjSize[node]; i++) {
            int next = adj[node][i].to;
            int w = adj[node][i].weight;

            if (!visited[next]) {
                push(next, w);
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adjSize[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u][adjSize[u]].to = v;
        adj[u][adjSize[u]].weight = w;
        adjSize[u]++;

        adj[v][adjSize[v]].to = u;
        adj[v][adjSize[v]].weight = w;
        adjSize[v]++;
    }

    printf("%d\n", prim(n));
    return 0;
}