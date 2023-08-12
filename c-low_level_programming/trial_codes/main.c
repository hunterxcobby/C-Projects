#include <stdio.h>

int main( int i, char *argv[]) 
{

	/*int i;*/

	/*printf("Number of arguments: %d\n", argc);*/

	for (i = 0; argv[i] != NULL; ++i) {
		printf("Argument %d: %s\n", i, argv[i]);
	}

	return 0;
}

