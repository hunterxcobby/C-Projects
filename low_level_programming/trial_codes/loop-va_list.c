#include <stdio.h>
#include <stdarg.h>

/*function prototype*/
int sum(int calc, ...);

int main(void)
{
	int n;
	n = sum(5, 20, 30, 40, 50, 60);

	/*printing sum*/
		printf("sum = %d \n", n);
	return 0;
}

int sum(int calc, ...)
{
	va_list addNumbers; /*give a name to the list*/
		va_start (addNumbers, calc); /*initiate the list*/

		int result = 0, i;

	/*Using a loop to access the numbers inputed*/
		for (i = 0; i < calc; i++)
		{
			result = result + va_arg (addNumbers, int);
		}
	va_end(addNumbers);
	return (result);
}
