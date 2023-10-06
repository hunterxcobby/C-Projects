#include "main.h"

int main(void)
{
    char *new_directory = "/usr/bin"; /* Example of a directory*/

    if (chdir(new_directory) == 0)
    {
        printf("Changed to /usr/bin\n");
    }
    else
    {
        perror("chdir");
        printf("failed to change dir");
    }

    return(0);
}