#include <stdio.h>
#include <dirent.h>

int main(void) {
    DIR *dir;
    struct dirent *entry;
    
    /* Open the current directory */
    dir = opendir(".");
    
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }
    
    /* Read and print the contents of the directory */
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    
    /* Close the directory when done */
    closedir(dir);
    
    return 0;
}
