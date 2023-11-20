#include "main.h"

/**
 * Function to sort an array using the quicksort algorithm
 * Do not forget to go through the readme 
 * and kindly check the bottom of this code too
 * 
*/
void quicksort(int *array, int low, int high)
{
    int location;

    /* Recursively sort the left and right sub-arrays*/
    if (low < high)
    {
        /* Find the partitioning point (location) for the array*/
        location = partition(array, low, high);

        /* Recursively sort the left and right sub-arrays*/
        quicksort(array, low, location - 1);
        quicksort(array, location + 1, high);
    }
}

/**
 * The function quicksort takes an array, its lower bound (low), and its upper bound (high) as parameters.
 * It checks if there is more than one element in the array to sort.
 * If so, it calls the partition function to find the partitioning point (location) for the array.
 * Then, it recursively applies the quicksort algorithm to the left and right sub-arrays.
 * This process continues until the entire array is sorted.
*/