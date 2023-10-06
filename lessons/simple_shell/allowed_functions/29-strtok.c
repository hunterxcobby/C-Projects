#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[] = "Hello,world,how,are,you";
    const char delimiters[] = ",";

    char *token = strtok(input, delimiters);

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delimiters);
    }

    return 0;
}
