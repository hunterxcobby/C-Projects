// Online C compiler to run C program online
#include <stdio.h>

int sum(int test1, int test2);

int main() 
{
	int test1 = 25;
	int test2 = 25;
	int total;

	total = sum(test1, test2);
	// whatever that is in sum, let total hold now

	printf("this is the total = %d \n ", total);

	return 0;
}

int sum(int test1, int test2)
{
	int n;
	int m;
	int total;
	int subtract;

	total = test1 + test2;
	subtract = test2 - test1;
	n = total;
	m = subtract;
	//subtract = test2 - test1;
	//printf("this is the total = %d \n ", total);

	return n;
}
