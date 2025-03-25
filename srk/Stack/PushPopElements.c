#include "Stack.h"

int main()
{
    Stack *newStack = createStack(5);

    push(newStack, 100);         printStackElements(newStack);
    push(newStack, 200);         printStackElements(newStack);
    push(newStack, 300);         printStackElements(newStack);
    push(newStack, 400);         printStackElements(newStack);
    push(newStack, 500);         printStackElements(newStack);
    push(newStack, 600);         printStackElements(newStack);
    printf("popped element %d, size %d\n", pop(newStack), newStack->top);   printStackElements(newStack);
    printf("popped element %d, size %d\n", pop(newStack), newStack->top);   printStackElements(newStack);

    printf("pushed element %d, size %d\n", push(newStack, 3), newStack->top +1); printStackElements(newStack);
    printf("popped element %d, size %d\n", pop(newStack), newStack->top);   printStackElements(newStack);
    printf("popped element %d, size %d\n", pop(newStack), newStack->top);   printStackElements(newStack);
    printf("popped element %d, size %d\n", pop(newStack), newStack->top);   printStackElements(newStack);
    printf("popped element %d, size %d\n", pop(newStack), newStack->top);   printStackElements(newStack);
    return 0;
}