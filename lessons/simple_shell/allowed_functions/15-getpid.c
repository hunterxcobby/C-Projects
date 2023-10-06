#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter a line of text: ");

    /* Read a line of text from stdin */
    read = getline(&line, &len, stdin);

    if (read != -1) {
        printf("Line read (%zd bytes): %s", read, line);
    } else {
        printf("Error reading line\n");
    }

    /* Free the allocated memory */
    free(line);

    return 0;
}
