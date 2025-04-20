#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

int main()
{
    int a = 10; 
    int b = 20;
    //Swap two numbers using pointers
    int *ptr1 = &a;
    int *ptr2 = &b;
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    printf("%d %d\n", a, b);
    return 0;
}