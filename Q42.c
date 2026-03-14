#include <stdio.h>
#define MAX 100
int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;
void enqueue(int x)
{
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n, i, x;

    scanf("%d", &n);
    // Input elements into queue
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }
    // Step 1: Move queue elements to stack
    for(i = 0; i < n; i++)
    {
        push(dequeue());
    }
    // Step 2: Move stack elements back to queue
    for(i = 0; i < n; i++)
    {
        enqueue(pop());
    }
    // Print reversed queue
    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}