#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main()
{
    char exp[100];
    int i = 0;

    printf("Enter postfix expression:\n");
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            int b = pop();
            int a = pop();
            int result;

            switch (exp[i])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }
        i++;
    }

    printf("Result = %d\n", pop());

    return 0;
}