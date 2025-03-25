#include"Arrays.h"

void PrintArray(int *Array, int ArraySize)
{
    printf("\nArraySize : %d", ArraySize);
    for (int i = 0; i < ArraySize; i++)
    {
        printf("\n%d", Array[i]);
    }
}