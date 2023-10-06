#include <stdio.h>
#include <dirent.h>

int main(void) {
    DIR *dir;
    struct dirent *entry;

    /* Open a directory stream */
    dir = opendir("/etc");
    if (dir == NULL) 
    {
        perror("opendir");
        return 1;
    }

    /* Read directory entries */
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    /* Close the directory stream */
    if (closedir(dir) == -1) {
        perror("closedir");
        return 1;
    }

    return 0;
}
