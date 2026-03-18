#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[rear++] = temp->left;

        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}