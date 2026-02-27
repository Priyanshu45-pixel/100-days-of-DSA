#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Append at end
void append(struct Node** head, int data) {
    struct Node* node = createNode(data);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = node;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n, m, x;

    // First list
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        arr[i] = x;
        append(&head1, x);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        append(&head2, x);
    }

    // Find intersection by value
    struct Node* temp = head2;
    while (temp) {
        for (int i = 0; i < n; i++) {
            if (temp->data == arr[i]) {
                printf("%d", temp->data);
                return 0;
            }
        }
        temp = temp->next;
    }

    printf("No Intersection");
    return 0;
}