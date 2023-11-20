#include <stdio.h>

/**
 * This is an implementation of an insertion sort algorithm
 * Please make sure to read the readme if you did not to grasps a solid
 * understanding of this algorithm and how it works
 * I have also implemeted other sort algorithms which you can checkout
 * 
 * Read the comments below for a summary of this code 
 * I have added comments to make it simple for you to follow along 
 * if you do not understand anything kindly let me know
*/


int main(void)
{
	/* Declare variables */
	int i;
	int j;
	int temp;

	/* Initialize an array of integers */
	int num[] = {4, 5, 10, 1, 6, 2};

	/* Calculate the size of the array */
	int numSize = sizeof(num) / sizeof(num[0]);

	/* Print the unsorted sublist */
	printf("This is the unsorted sublist\n");
	for (i = 0; i < numSize; i++)
	{
		printf("[%d]\n", num[i]);
	}

	/* Insertion Sort Algorithm: Sorting the array in ascending order */
	for (i = 1; i < numSize; i++)
	{
		temp = num[i];
		j = i - 1;

		/* Compare and shift elements to insert the current element in the correct position */
		while (j >= 0 && num[j] > temp)
		{
			num[j + 1] = num[j];
			j--;
		}
		num[j + 1] = temp; /* Insert the current element in the correct position*/
	}

	/* Print the sorted list */
	printf("This is the sorted list\n");
	for (i = 0; i < numSize; i++)
	{
		printf("[%d]\n", num[i]);
	}

	/* Return 0 to indicate successful execution */
	return (0);
}

/**
 * The code uses the Insertion Sort algorithm to sort an array of integers in ascending order and then prints the sorted array.
 * The Insertion Sort algorithm works by dividing the array into a sorted and an unsorted region. It iterates through the unsorted region,
 * taking one element at a time and inserting it into its correct position in the sorted region, shifting other elements if necessary.
 * The sorted array is then printed to the console.
 */
