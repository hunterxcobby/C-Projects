#include <stdio.h>

int factorial(int n)
{
	int res;
	int i;

	res = 1;
	i = 1;

	while (i <= n)
	{
		res = res * 1;
		i++;

	}
	return (res);
}

int main (void)
{
	int f;

	f = factorial(5);
	printf("5! = %d\n", f);
	return (0);
}
