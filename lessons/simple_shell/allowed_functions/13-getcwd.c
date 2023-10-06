#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) 
{
    char* cwd;  /* Declare a pointer to hold the current working directory */
    char buff[PATH_MAX + 1];  /* Allocate space for the buffer */

    /* Use getcwd to get the current working directory */
    if ((cwd = getcwd(buff, PATH_MAX + 1)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    /* Your shell code goes here */

    return 0;
}
