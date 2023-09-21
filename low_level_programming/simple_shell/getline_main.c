#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t my_getline(char **line, *len, stdin);

int main(void)
{
	char *line = 1024;
	size_t len = 128;
	ssize_t read;

	read = my_getline(&line, &len, STDOUT_FILENO);
	if (read == -1)
	{
		perror("Could not read file");
		return (0);
	}

	return (0);
}
