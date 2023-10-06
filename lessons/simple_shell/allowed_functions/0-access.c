#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *file_path = "acces";
    int permissions = F_OK; /*Check for read permissions*/

if (access(file_path, permissions) == 0)
{
    printf("This file exists\n");
}
else
{
    perror("This file does not exist");
    exit(1);
}
    return(0);
}