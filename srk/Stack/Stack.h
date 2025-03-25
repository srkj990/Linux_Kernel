#include <stdio.h>
#include <stdlib.h>

typedef struct Stack 
{
    int top, cap;
    int *array;
}Stack;

Stack * createStack(int cap);
void printStackElements(Stack * stack);
int push(Stack *stack, int data);
int pop(Stack *stack);