#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int top = -1;
int stack[MAX_SIZE];

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack is full. Cannot push %d.\n", value);
        return;
    }
    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack[top--];
}

void printStack()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    push(1);
    push(2);
    push(3);
    printStack(); // prints: 1 2 3
    pop();
    printStack(); // prints: 1 2
    return 0;
}