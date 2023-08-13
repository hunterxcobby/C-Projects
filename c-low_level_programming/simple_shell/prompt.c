#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = NULL;
    size_t len = 1024;
    ssize_t read;
    
    
    
    while (1)
    {
        printf("$ ");
    read = getline(&buffer, &len, stdin);
       
         if (read != -1)
        {
            printf("$ %s", buffer);
        }
        else
        {
            printf("Error reading input.\n");
            break;
        }
        
        if (read == 1 && buffer[0] == '\n') {
            break;
        }
    }
    
        free(buffer);
        return 0;
}
