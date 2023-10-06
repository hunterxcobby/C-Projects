#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
    struct stat st;

    if (stat("file.txt", &st) == 0) {
        printf("Size of file: %ld bytes\n", st.st_size);
        printf("Mode: %o\n", st.st_mode);
    } else {
        perror("stat");
    }

    return 0;
}
