#include <stdio.h>

/**
 * main - Entry point
 * Description: Using while loop to print nunbers that will ignore a betty line check of eithty characters
 * Return: Always return 0
 */

int main(void)
{

	int num = 1;

	while (num <= 10)/*condition*/
	{
		printf("%d \n", num);
		num = num + 1; /*variable increases*/
	}
	return (0);
}
