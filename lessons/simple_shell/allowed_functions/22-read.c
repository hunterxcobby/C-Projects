#include <unistd.h>

int main(void) 
{
    char buffer[1024]; /* Declare a buffer to store the read data*/
    ssize_t bytesRead; /* Store the number of bytes actually read*/
    
    bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer)); /* Read from standard input (keyboard)*/
    
    if (bytesRead > 0) {
        write(STDOUT_FILENO, buffer, bytesRead); /* Write the read data to standard output (console)*/
    }
    
    return 0;
}
