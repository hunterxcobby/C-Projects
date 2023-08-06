#include <stdio.h>

/**
 * bitwise_and - Compute the bitwise AND of two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The result of the bitwise AND operation.
 */
int bitwise_and(int a, int b);

int main(void)
{
	int result;

	int a = 3;
	int b = 5;

	/* Call the bitwise_and function and store the result in 'result' variable */
	result = bitwise_and(a, b);

	/* Print the result of the bitwise AND operation */
	printf("%d\n", result);

	return 0;
}

/**
 * bitwise_and - Compute the bitwise AND of two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The result of the bitwise AND operation.
 */

int bitwise_and(int a, int b) {
	return a & b;
}
