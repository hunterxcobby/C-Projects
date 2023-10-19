#include "main.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int fd;/* The file descriptor*/
	int line_number = 1;/* LIne number will always start at one*/
	char *line;/* Initialize a buffer to read lines from the file */
	ssize_t read_data;
	char *token;
	char *delimiter = "\n\t\r\a ;:";

	/* user does not give any file or more than one argument to your program*/
	if (argc != 2 || !argv[1])
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* We open a file*/
	fd = open(argv[1], O_RDONLY);
	/* If it’s not possible to open the file, print the error message*/
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Allocate memory space*/
	line = malloc(sizeof(char) * 1024);
	/* if you can’t malloc anymore, print the error message */
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Read from the file */
	read_data = read(fd, line, 1024);
	/* If we are not able to read the contents of the file*/
	if (read_data == -1)
	{
		free(line);
		exit(EXIT_FAILURE);
	}

	/* We tokenize the data*/
	token = strtok(line, delimiter);
	line_number++;
	token = strtok(NULL, delimiter);


	free(line);
	close(fd);
	return (0);
}
