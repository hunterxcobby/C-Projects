#include "main.h"

/**
 * This is an iimplementation of the merge sort algorithm
 * 
 * please read the readme file if you have not
 * below this function is a summary of what the function is doing
*/

void mergeSort(int *array, int leftHalf, int rightHalf)
{
    int mid; /* Declare a variable to store the middle index of the array */

    /* Check if the left index is less than the right index */
    if (leftHalf < rightHalf)
    {
        /* Calculate the middle index of the array */
        mid = (leftHalf + rightHalf) / 2;

        /* Recursively call mergesort on the left half of the array */
        mergeSort(array, leftHalf, mid);

        /* Recursively call mergesort on the right half of the array */
        mergeSort(array, mid + 1, rightHalf);

        /* Call the merge function to merge the sorted halves */
        merge(array, leftHalf, mid, rightHalf);
    }
}

/**
 * This function is the first step of the merge sort algorithm, 
 * which is a divide-and-conquer sorting algorithm. 
 * THe function recursively divides the array into smaller halves 
 * until each sub-array has one element (considered sorted)
 * and then merges these sorted halves back together.
*/