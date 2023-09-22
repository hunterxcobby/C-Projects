#include "main.h"

/* file responsible for the end of operations */

int askContinue(void)
{
	char choice;

	printf("\nDo you want to perform another calculation? (y/n): \n");
	scanf(" %c", &choice);
	return (choice);

	while(getchar() != '\n')
		continue;

	return (choice);
}
