#include "Arrays.h"

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(int);
    PrintArray(&arr[0], length);
    return 0;
}