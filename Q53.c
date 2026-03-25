#include <stdio.h>
#include <stdlib.h>
// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// Queue for BFS
struct QueueNode {
    struct Node* node;
    int hd;
};
struct Queue {
    int front, rear;
    struct QueueNode arr[1000];
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct QueueNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Queue q;
    q.front = q.rear = 0;

    // Map using array (HD range assumed)
    int map[2000][100];
    int count[2000] = {0};

    int offset = 1000;

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {
        struct QueueNode temp = dequeue(&q);
        struct Node* curr = temp.node;
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = curr->data;

        if (curr->left)
            enqueue(&q, curr->left, temp.hd - 1);
        if (curr->right)
            enqueue(&q, curr->right, temp.hd + 1);
    }

    // Print result
    for (int i = 0; i < 2000; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue q;
    q.front = q.rear = 0;

    enqueue(&q, root, 0);

    int i = 1;
    while (!isEmpty(&q) && i < n) {
        struct Node* curr = dequeue(&q).node;

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left, 0);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right, 0);
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}