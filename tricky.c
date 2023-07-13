#include <stdio.h>
#include <stdlib.h>

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
	char *str;

	str = malloc(sizeof(char) * 3);
	str[0] = 'B';
	str[1] = 'A';
	str[2] = 'B';
	str[3] = 'Y';
	str[4] = '\0';

	str[3] = 'L';

	printf("%s\n", str);
	return (0);
}
