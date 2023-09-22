#include "main.h"

void mixed_operations(void)
{

	int max_operations = 15;
	int operation_count = 0;
        char operation;
        double number;

        double result;

	double numbers[15];
	char operations[15];


	/* Collect operations and numbers from the user*/
	printf("Enter operations and numbers (enter 0 as operation to finish):\n");
	while (1) {
		scanf(" %c", &operation); /* Note the space before %c to skip whitespace characters*/
		if (operation == '0') {
			break;
		}

		scanf("%lf", &number);
		operations[operation_count] = operation;
		numbers[operation_count] = number;

		operation_count++;

		if (operation_count == max_operations) {
			printf("Maximum number of operations reached.\n");
			break;
		}
	}

	/*Call the calculate function with collected data*/
	result = mixed(2 * operation_count, numbers[0], operations[0], numbers[1], operations[1], 0);
	printf("Result: %.2f\n", result);
}
