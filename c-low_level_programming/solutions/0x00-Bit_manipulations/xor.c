#include <stdio.h>

/**
 * remove_double - Finds the integer that occurs only once in the array
 * @arr: The input array containing integers with duplicates
 * @size: The size of the array
 *
 * Description:
 * The function uses the XOR bitwise operation to find the integer that
 * occurs only once in the array where all other integers appear exactly twice.
 *
 * Return:
 * The integer that occurs only once in the array.
 */

int remove_double(int arr[], int size);

int main(void)
{
	int arr[] = {2, 1, 2, 5, 6, 5, 7, 7, 6};
	int size = sizeof(arr) / sizeof(arr[0]); /*Calculate the size of the array*/

	int singleInt = remove_double(arr, size);
	printf("The integer that occurs only once: %d\n", singleInt);

	return 0;
}

/**
 * remove_double - Finds the integer that occurs only once in the array
 * @arr: The input array containing integers with duplicates
 * @size: The size of the array
 *
 * Description:
 * The function uses the XOR bitwise operation to find the integer that
 * occurs only once in the array where all other integers appear exactly twice.
 *
 * Return:
 * The integer that occurs only once in the array.
 */
int remove_double(int arr[], int size)
{
	int result = 0;
	int i;
	/*XOR all the elements of the array*/
	for ( i = 0; i < size; i++)
	{
		result ^= arr[i];
	}

	return result;
}

