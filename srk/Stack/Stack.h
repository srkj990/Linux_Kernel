#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_Array 
{
    int top, cap;
    int *array;
}Stack_Array;

Stack_Array * createStack(int cap);
void printStackElements(Stack_Array * stack);
int push(Stack_Array *stack, int data);
int pop(Stack_Array *stack);