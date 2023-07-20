#include <stdio.h>

/* The function prototypes*/
int sum(int x, int y);
int avg(int (*ptsum)(int, int), int a, int b);

int main() 
{
	/* initializing a pointer to sum function*/
	int (*ptsum)(int, int);
	ptsum = &sum;

	/*Printing the address of sum*/
		printf("This is the address of the sum function = %p \n", &sum);

	/* Printing sum*/
	int s;
	s = sum(5,7);
	printf("sum is:%d \n", s);

	/* Printing average */
	int a;
	a = avg(ptsum, 5, 7);
	printf("Average is: %d \n", a);
	return 0;
}

/* Definition of the sum function*/
int sum(int x, int y)
{
	return(x + y);
}

	/*Definition of the average function*/
int avg(int (*ptsum)(int, int), int a, int b)
{

	int n = ptsum(a,b);
	int x = 2;
	int average;
	average = n / x; 
	return (average);
}
