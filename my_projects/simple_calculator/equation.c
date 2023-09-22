#include "main.h"
#include <stdio.h>

// this is the part of the code responsible for building the the equation, the function takes 4 arguments .
// (1arg) the operation(the arithmetic operation character eg +, 
// (2arg)num_values  thats the number of values involved int the operation
// (3arg) the result of the calculation
// (4arg) to access the value
void buildEquation(char operation, int num_values, double values[], double result)
{
	int i;
	printf("Equation: %.2lf", values[0]);
	for (i = 0; i < num_values; i++)
	{
		printf(" %c %.2lf", operation, values[i]);
	}
	printf(" = %.2lf\n", result);
}
