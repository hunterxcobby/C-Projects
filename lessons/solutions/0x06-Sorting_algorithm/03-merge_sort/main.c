#include "main.h"

#define LEFT_START 0
#define RIGHT_END (arr_size - 1)

int main(void)
{
    int i;
    int arr[] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr,LEFT_START, RIGHT_END);

    printf("Sorted Array: ");
    for (i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
