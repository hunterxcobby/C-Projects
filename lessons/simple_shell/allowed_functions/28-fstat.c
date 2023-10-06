#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) 
{
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == 0) {
        printf("Size of file: %ld bytes\n", st.st_size);
        printf("Mode: %o\n", st.st_mode);
    } else {
        perror("fstat");
    }

    close(fd);

    return 0;
}
