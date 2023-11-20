#include "main.h"

/* Function to merge two halves of an array during the merge sort process */
void merge(int *array, int leftHalf, int mid, int rightHalf)
{
    int i, j, k; /* Declare variables for indices in the merging process */
    int *temp = malloc((rightHalf - leftHalf + 1) * sizeof(int));
/* Declare an array to temporarily store merged values */
    
    i = leftHalf; /* Initialize index i to the start of the left half */
    j = mid + i; /* Initialize index j to the start of the right half */
    k = 0; /* Initialize index k to the start of the merged array */

    /* Iterate while both halves have elements */
    while (i <= mid && j <= rightHalf)
    {
        /* Compare elements at indices i and j */
        if (array[i] <= array[j])
        {
            /* If equal or less, assign the element at index i to the temp array */
            temp[k] = array[i];
            i++;
        }
        else
        {
            /* If greater, assign the element at index j to the temp array */
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    /* If elements remain in the left half, copy them to the temp array */
    if (i > mid)
    {
        while (j <= rightHalf)
        {
            temp[k] = array[j];
            j++;
            k++;
        }
    }
    else /* If elements remain in the right half, copy them to the temp array */
    {
        while (i <= mid)
        {
            temp[k] = array[i];
            i++;
            k++;
        }
    }

    /* Copy the merged values from the temp array back to the original array */
    for (k = leftHalf; k <= rightHalf; k++)
    {
        array[k] = temp[k];
    }

    free(temp);
}

/**
 * this function takes two sorted halves of an array and merges them into a single sorted array. 
 * It's a key step in the merge sort algorithm, which is a way to efficiently sort an array. 
 * The temporary array (temp) is used to hold the merged elements temporarily.
*/