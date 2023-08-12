#include <stdio.h>

/**
 * is_even - Checks if a number is even or odd using bitwise AND.
 *
 * @num: The number to be checked.
 *
 * Return: 1 if the number is even, 0 if the number is odd.
 */
int is_even(int num);

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int num = 3;
	int result = is_even(num);

	if (result == 1)
	{
		printf("Number is even\n");
	}
	else
	{
		printf("Number is odd\n");
	}

	return 0;
}

/**
 * is_even - Checks if a number is even or odd using bitwise AND.
 *
 * @num: The number to be checked.
 *
 * Return: 1 if the number is even, 0 if the number is odd.
 */
int is_even(int num)
{
	if ((num & 1) == 0)
	{
		return 1; /* Even*/
	}
	else
	{
		return 0; /* Odd*/
	}
}

