#include <stdio.h>


int main(void)
{
	/* Declare variables */
	int i;
	int j;
	int temp;
	int flag;

	/* Initialize an array of integers */
	int num[] = {15, 16, 6, 8, 5};

	/* Calculate the size of the array */
	int numSize = sizeof(num) / sizeof(num[0]);

	/* Bubble Sort Algorithm: Sorting the array in ascending order */
	for (i = 0; i < numSize - 1; i++)
	{
		/* Initialize a flag to check if any swaps occur during a pass */
		flag = 0;

		/* Inner loop to perform comparisons and swaps */
		for (j = 0; j < numSize - 1; j++)
		{
			/* Compare adjacent elements, swap if necessary */
			if (num[j] > num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;

				/* Set the flag to indicate a swap occurred */
				flag = 1;
			}
		}

		/* Check if no swaps occurred in this pass, meaning the array is already sorted */
		if (flag == 0)
		{
			printf("The array is already sorted.\n");
			/* Exit the loop early since the array is sorted */
			break;
		}
	}

	/* Print the sorted array */
	printf("The sorted array is\n");
	for (i = 0; i < numSize; i++)
	{
		printf("[%d]\n", num[i]);
	}

	/* Return 0 to indicate successful execution */
	return (0);
}
