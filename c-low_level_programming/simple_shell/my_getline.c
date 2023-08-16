#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * my_getline - Reads the line of a text
 * @len: the size of the buffer
 * @line: a pointer to the buffer
 * @stream: the file stream
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
			return -1;
		}
	}

	getline = fgets(*line, *len, stream);
	if (getline != EOF)
	{
		read = strlen(*line);

		if (read > 0 && (*line)[read - 1] == '\n');
		{
			(*line)[read - 1] = '\0';
			read --;
		}
		return (read);
	}
	else
	{
		return (-1);
	}
	// return(getline);
}

