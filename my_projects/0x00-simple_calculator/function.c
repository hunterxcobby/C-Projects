#include "main.h"

/* ADDITION */
int add(int count, ...)
{

	va_list numbers;
	int result;
	int i;
	va_start(numbers, count);

	result = 0;

	/* accessing all members of the list*/
	for (i = 0; i < count; i++){
		result = result + va_arg(numbers, int);
	}

	/*while((value = va_arg(numbers, int)) != 0)
	  {
	  result += value;
	  }*/

	va_end(numbers);
	return (result);
}


/* SUBTRACTION */
int sub(int count, ...)
{
	va_list numbers;
	int result;
	int i;

	va_start(numbers, count);

	result = va_arg(numbers, int);

	for (i = 1; i < count; i++)
	{
		result -= va_arg(numbers, int);
	}

	va_end(numbers);
	return(result);
}


/* MULTIPLICATION */
int multiply(int count, ...) 
{
	va_list numbers;
	int result = 1; /*Initialize with 1 for multiplication*/
	int i;
	va_start(numbers, count);

	/* accessing all members of the list */
	for (i = 0; i < count; i++) {
		result *= va_arg(numbers, int);
	}

	va_end(numbers);
	return result;
}

/* DIVISION */
double divide(int count, ...) 
{
	va_list numbers;
	double result;
	int i;
	double next_value;
	va_start(numbers, count);

	result = va_arg(numbers, double); /*Initialize with the first value*/

	/* accessing all members of the list (starting from the second value) */
	for (i = 1; i < count; i++) 
	{
		next_value = va_arg(numbers, double);

		if (next_value != 0) {
			result /= next_value;
		} else {
			printf("Error: Division by zero\n");
			va_end(numbers);
			return 0.0;
		}
	}

	va_end(numbers);
	return result;
}

/* MIXED OPERATIONS */

double mixed(int count, ...) 
{
	va_list args;
	double result;
	double value;
	char operation;
	int i;
	va_start(args, count);

	result = va_arg(args, double); 

	/*if (count % 2 == 0)
	 {
		printf("Error: Invalid number of arguments\n");
		return 0;
	}*/

	for (i = 1; i < count; i += 2)
	{
		operation = va_arg(args, int);
		value = va_arg(args, double);

		switch (operation) {
			case '+':
				result += value;
				break;
			case '-':
				result -= value;
				break;
			case '*':
				result *= value;
				break;
			case '/':
				if (value != 0) {
					result /= value;
				} else {
					printf("Error: Division by zero\n");
					va_end(args);
					return 0;
				}
				break;
			case '0':
				continue;
			default:
				printf("Invalid operation\n");
				va_end(args);
				return 0;
		}

	}

	va_end(args);
	return result;
}
