#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY); /* Open a file for reading */
    if (fd == -1) {
        perror("open");
        return 1;
    }

    /* Perform operations using the file descriptor */

    int result = close(fd); /** Close the file descriptor */
    if (result == -1) {
        perror("close");
        return 1;
    }

    return 0;
}
