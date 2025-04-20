#include <stdlib.h>

int main()
{
    // Dynamic memory allocation
    int *arr = (int *)malloc(10 * sizeof(int));

    if (arr == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Use the allocated memory
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i * 2;
    }

    free(arr); // Release memory
    return 0;
}