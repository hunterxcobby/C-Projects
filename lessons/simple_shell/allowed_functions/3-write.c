#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = 1; /* File descriptor 1 represents standard output (stdout)*/
    const char *message = "Hello, World!\n";
    ssize_t bytes_written = write(fd, message, strlen(message));

    if (bytes_written == -1) 
    {
        perror("write");
    } else
    {
        printf("Bytes written: %zd\n", bytes_written);
    }

    return 0;
}
