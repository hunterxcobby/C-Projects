#include <stdio.h>
#include <unistd.h>


int main (void)
{
    const char pathname[] = "/bin/ls";
    char *const argv[] = { "ls", "-l", NULL};
    /*char *const envp[] = NULL;*/

    execve(pathname, argv, NULL);
    
    return (0);
}
