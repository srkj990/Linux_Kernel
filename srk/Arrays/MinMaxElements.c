#include "Arrays.h"

int main()
{
    int arr[] = {111, 245, 345, 24, 512};
    int length = sizeof(arr) / sizeof(int);
    int min = arr[0], max = arr[0];

    PrintArray(&arr[0], length);

    for (int i = 0; i < length; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("\nMin: %d, Max: %d\n", min, max);
    return 0;
}