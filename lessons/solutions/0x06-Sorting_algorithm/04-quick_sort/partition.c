#include "main.h"

/**
 * Function to partition the array for the Quick Sort algorithm.
 * This function is part of the Quick Sort algorithm, 
 * which is a sorting algorithm. 
 * It's designed to efficiently sort an array of elements.
 * Check out the readme to know why we need to partition in this algorithm
 * 
 * despite,below these codes are a summary / explanation to this function 
*/

int partition(int *array, int low, int high)
{
	int pivot;
	int start;
	int end;

    /* Choose the pivot as the element at the low index*/
	pivot = array[low];

    /* Initialize start and end indices*/
	start = low;
	end = high;

    /* Continue until the start index is less than the end index*/
	while (start < end)
	{
        /* Find an element greater than the pivot from the left*/
		while(array[start] <= pivot)
		{
			start++;
		}
        /* Find an element greater than the pivot from the left*/
		while(array[end] > pivot)
		{
			end--;
		}

        /*  Swap the elements at the start and end indices*/
		if (start < end)
		{
			swap(&array[start], &array[end]);
		}
	}
    /* Swap the pivot with the element at the end index*/
	swap(&array[low], &array[end]);
	return (end);
}

/**
 * In simpler terms, the function helps organize a row of books by choosing a starting book,
 * rearranging them so that smaller books are on one side and larger books on the other, 
 * and finally telling you where the starting book (pivot) is in its new organized position. 
 * This process is a part of a bigger strategy called Quick Sort used to efficiently sort a bunch of elements.
*/