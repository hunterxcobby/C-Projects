#include <stdio.h>
#include <dirent.h>

int main(void) 
{
    DIR *directory;
    struct dirent *entry;

    /* Open the current directory */
    directory = opendir(".");
    if (directory == NULL) {
        perror("opendir");
        return 1;
    }

    /* Read each entry in the directory */
    while ((entry = readdir(directory)) != NULL) {
        /* Print the name of the entry */
        printf("%s\n", entry->d_name);
    }

    /* Close the directory stream */
    closedir(directory);
    return 0;
}
