#include <stdio.h>

int main(void) {
    FILE *file;
    
    /* Attempt to open a non-existent file */
    file = fopen("nonexistent.txt", "r");
    
    if (file == NULL) {
        perror("fopen");
    }
    
    return 0;
}
