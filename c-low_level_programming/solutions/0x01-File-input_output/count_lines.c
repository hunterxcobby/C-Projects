#include <stdio.h>
#include <unistd.h>

/**
 * main - Reads a file and counts the number of lines.
 * note: remember this is to only help you understand
 * Return: 0 on success, 1 on error.
 */
int main(void)
{
    // Declare variables
    FILE *file;      // File pointer
    char ch;         // Character read from the file
    int lineCount;   // Counter for lines

    // Open the file "input.txt" for reading
    file = fopen("input.txt", "r");

    // Check if the file opening was successful
    if (file == NULL)
    {
        perror("Error opening file"); // Print an error message
        return 1; // Return 1 to indicate an error
    }

    // Initialize the line count to zero
    lineCount = 0;

    // Read characters from the file until the end of file (EOF) is reached
    while ((ch = fgetc(file)) != EOF) 
    {
        // Check if the current character is a newline character
        if (ch == '\n') 
            lineCount++; // Increment the line count
    }

    // Print the total line count
    printf("%d\n", lineCount);

    // Close the file
    fclose(file);

    // Return 0 to indicate successful execution
    return 0;
}

