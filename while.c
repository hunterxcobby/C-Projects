#include <stdio.h>

/**
  Description - Using while loop to print nunbers
  */

int main() {

	int num = 1;

	while(num <= 10) //condition
	{
		//printf("This is a while loop\n");
		printf("%d \n", num);
		num = num + 1; //variable increases
	}
	return 0;
}
