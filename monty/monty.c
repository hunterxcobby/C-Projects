#include "main.h"

/**
 * 
 */

int main(int argc, char *argv[])
{
    int fd;
    /*char *file_name;*/

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
		close(fd);
		exit(EXIT_FAILURE);
    }

    return (0);
}