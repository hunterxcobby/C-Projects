#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

ssize_t my_getline(char **line, size_t *len, FILE *stream);

/**
 * main - Entry point
 *
 * Return: Return 0 for success
*/


int main(void)
{

	char *buffer = NULL;
	size_t len = 1024;
	ssize_t read;




	{
		printf("$ ");
		read = getline(&buffer, &len, stdin);

		if (read != -1)
		{
			printf("%s", buffer);
		}
		else
		{
			printf("Error reading input.\n");
			return (1);
		}

		if (read == 1 && buffer[0] == '\n')
		{
			return (1);
		}
	}

	free(buffer);
	return (0);
}

/**
 * my_getline - Reads the line of a text
 * @len: the size of the buffer
 * @line: a pointer to the buffer
 * @stream: the file stream
 *
 * Return: return 0 to indicate success
 */

ssize_t my_getline(char **line, size_t *len, FILE *stream)
{

	char *getline;
	ssize_t read;

	if (*line == NULL || *len == 0)
	{
		*len = 1024;
		*line = malloc(*len);
		if (*line == NULL)
		{
			return (-1);
		}
	}

	getline = fgets(*line, *len, stream);
	if (getline != NULL)
	{
		read = strlen(*line);

		if (read > 0 && (*line)[read - 1] == '\n')
		{
			(*line)[read - 1] = '\0';
			read--;
		}
		return (read);
	}
	else
	{
		return (-1);
	}

}

