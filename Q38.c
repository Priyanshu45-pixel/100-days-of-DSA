#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int deque[MAX];
int front = -1;
int rear = -1;

int empty() {
    return (front == -1);
}

int size() {
    if (front == -1)
        return 0;
    return rear - front + 1;
}

void push_front(int value) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = value;
    }
    else if (front > 0) {
        front--;
        deque[front] = value;
    }
    else {
        printf("Deque Overflow at Front\n");
    }
}

void push_back(int value) {
    if (rear == MAX - 1) {
        printf("Deque Overflow at Rear\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    deque[rear] = value;
}

void pop_front() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

int get_front() {
    if (empty()) {
        printf("Deque Empty\n");
        return -1;
    }
    return deque[front];
}

int get_back() {
    if (empty()) {
        printf("Deque Empty\n");
        return -1;
    }
    return deque[rear];
}

void clear() {
    front = rear = -1;
}

void reverse() {
    int i = front, j = rear, temp;
    while (i < j) {
        temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void sort() {
    int i, j, temp;

    for (i = front; i <= rear; i++) {
        for (j = i + 1; j <= rear; j++) {
            if (deque[i] > deque[j]) {
                temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

void display() {
    if (empty()) {
        printf("Deque Empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);

    display();

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());

    pop_front();
    display();

    push_back(15);
    push_back(30);

    reverse();
    printf("After Reverse:\n");
    display();

    sort();
    printf("After Sort:\n");
    display();

    printf("Size: %d\n", size());

    clear();
    printf("After Clear:\n");
    display();

    return 0;
}