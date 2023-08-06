#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int a_very_long_variable_name = 42;

	/*This line exceeds 80 characters, but it's necessary for clarity*/
	printf("The value of the variable is: %d\n",
	a_very_long_variable_name);

	return (0);
}
