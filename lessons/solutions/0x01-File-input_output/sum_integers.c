#include <stdio.h>
#include <unistd.h>

int main() 
{
	FILE *file;      // Declare a file pointer
	int a;           // Variable to store the read character
	int sum = 0;     // Variable to store the sum of numbers

	file = fopen("numbers.txt", "r");   // Open the file in read mode
	if (file == NULL)
	{
		perror("this does not exist!"); // Print error message if file doesn't exist
		return 1;
	}

	while((a = getc(file)) != EOF)     // Read characters until EOF
	{
		sum = sum + a - '0';           // Convert character to integer and add to sum
	}

	printf("Sum: %d\n", sum);           // Print the sum

	fclose(file);  // Close the file

	return 0;
}

