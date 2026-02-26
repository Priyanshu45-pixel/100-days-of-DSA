#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
int main() {
    int n, i, val;
    struct node *head = NULL, *tail = NULL, *newnode;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &val);

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}