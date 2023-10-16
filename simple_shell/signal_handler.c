#include "main.h"

void signal_handler(int signal)
{
    char *prompt = "\nshell$ ";
    
    (void)signal;
    write(1, prompt, strlen(prompt));
    fflush(stdout);
}