#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

int main() {
    int n, key, count = 0;
    struct node *head = NULL, *temp = NULL, *newnode;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    scanf("%d", &key);

    temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}