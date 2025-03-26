

#include "stack.h"

Stack_Array * createStack(int cap)
{
    printf("Created a stack with capacity %d\n", cap);
    Stack_Array * stack = (Stack_Array *)malloc(sizeof(Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->array = (int *)malloc(cap * sizeof(int));
    return stack;
}
void printStackElements(Stack_Array * stack)
{
    if(stack->top < 0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack size :%d elements: ", stack->top + 1);
        for(int i = 0; i <= stack->top; i++)
        {
            printf("%d ", stack->array[i]);
        }
        printf("\n");
    }
}
int push(Stack_Array *stack, int data)
{
    if (stack->top == (stack->cap - 1))
    {
        printf("push : Stack is full\n");
        return -1;
    }
    else
    {
        stack->top++;
        stack->array[stack->top] = data;
        printf("Pushed  element %d \n", data);  
    }
    return data;
}
int pop(Stack_Array *stack)
{
    if (stack->top < 0)
    {
        printf(" pop : Stack is empty\n");
        return -1;
    }
    else
    {
        int item = stack->array[stack->top];
        stack->top--;
        printf("popped  element %d \n", item);  
        return item;
    }
}