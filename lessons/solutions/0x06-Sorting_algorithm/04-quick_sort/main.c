#include "main.h"

int main(void)
{
    int i; /* Declare a variable for loop iteration */
    int high = 0; /* Initialize the high index for quicksort */
    int arr[] = {7, 6, 10, 5, 2, 1, 15, 7}; /* Declare and initialize an array */
    int arr_size = sizeof(arr) / sizeof(arr[0]); /* Calculate the size of the array */
    int low = arr_size - 1; /* Initialize the low index for quicksort */

    printf("Original Array: ");
    for (i = 0; i < arr_size; i++) /* Loop to print the original array */
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, high, low); /* Call the quicksort function to sort the array */

    printf("Sorted Array: ");
    for (i = 0; i < arr_size; i++) /* Loop to print the sorted array */
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return (0); /* Indicates successful program execution */
}
