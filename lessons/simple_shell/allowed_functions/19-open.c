#include <stdio.h>
#include <fcntl.h>

int main(void) {
    int fd;
    
    /* Open a file in read-only mode */
    fd = open("example.txt", O_RDONLY);
    
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    printf("File descriptor: %d\n", fd);
    
    /* Close the file when done */
    close(fd);
    
    return 0;
}
