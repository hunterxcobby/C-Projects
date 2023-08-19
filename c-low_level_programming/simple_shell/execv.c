#include <stdio.h>
#include <unistd.h>


int main (void)
{
    const char pathname[] = "/bin/mkdir";
    char *const argv[] = { "mkdir", "shell", NULL};
    /*char *const envp[] = NULL;*/

    execve(pathname, argv, NULL);
    
    return (0);
}
