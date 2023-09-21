#include <stdio.h>
#include <stdarg.h>

/*function prototype*/
int sum(int m, int n, ...);

int main(void)
{
	int n;
	n = sum(10, 20, 30, 40, 50, 60);

	/*printing sum*/
		printf("sum = %d \n", n);
	return 0;
}

/** function definition**/
int sum(int m, int n, ...)
{
	va_list addNumbers; /*give a name to the list*/
		va_start (addNumbers, n); /*initiate the list*/

		/* Initializing variables to the added numbers*/
		int o = va_arg (addNumbers, int);   	 int p = va_arg (addNumbers, int);
	int result;
	result = m + n + o + p; 

	return (result);
}
