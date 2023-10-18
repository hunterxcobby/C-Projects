#include "main.h"

/**
 * 
 */

int main(int argc, char *argv[])
{
    int fd;/* The file descriptor*/
    char line[1024];/* Initialize a buffer to read lines from the file */
    int line_number = 1;/* LIne number will always start at one*/

    /* user does not give any file or more than one argument to your program*/
    if (argc != 2 || !argv[1])
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* We try to open a file*/
    fd = open(argv[1], O_RDONLY);
    /* If, for any reason, it’s not possible to open the file, print the error message*/
    if (fd == -1)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
    }

    close(fd);
    return (0);
}