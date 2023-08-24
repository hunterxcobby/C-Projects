#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char *_strncat(char *dest, const char *src, size_t n);
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char s1[98] = "Hello ";
	char s2[] = "World!\n";
	char *ptr;

	printf("%s\n", s1);
	printf("%s", s2);
	ptr = _strncat(s1, s2, 1);
	printf("%s\n", s1);
	printf("%s", s2);
	printf("%s\n", ptr);
	ptr = _strncat(s1, s2, 1024);
	printf("%s", s1);
	printf("%s", s2);
	printf("%s", ptr);

	return (0);
}

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t d_len = strlen(dest);
	size_t s_len = strnlen(src, n);
	char *string = NULL;
	size_t x;
	size_t y;

	string = malloc(d_len + s_len + 1);
	if (string == NULL)
	{
		return (NULL);
	}

	for (x = 0; x < d_len; x++)
	{
		string[x] = dest[x];
	}

	for (y = 0; y < s_len; y++)
	{
		string[d_len + y] = src[y];
	}

	string[d_len + y] = '\0';

	return (string);

}
