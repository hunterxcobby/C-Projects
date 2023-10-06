#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
    struct stat st;

    if (lstat("link_to_file.txt", &st) == 0) 
    {
        if (S_ISLNK(st.st_mode)) {
            printf("It's a symbolic link!\n");
        } else {
            printf("It's a regular file!\n");
        }
    } else {
        perror("lstat");
    }

    return 0;
}
