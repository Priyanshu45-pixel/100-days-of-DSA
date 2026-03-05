#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, m, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        if(top != -1)
            pop();
    }

    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}