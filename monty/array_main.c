#include "main.h"

/**
 * 
 * 
*/


int main(void)
{
	printf ("ARRAY IMPLEMENTATION OF STACKS\n\n");
	top = -1; /* Initializing top to -1 indicates that it is empty*/
	
    
    do
	{
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
                {
                    push();
                    break;
                }
			case 2:
                {
                    pop();
                    break;
                }
			case 3:
                {
                    display();
                    break;
                }
			case 4:
                {
                    exit(0);
                    break;
                }
			default:
                {
                    printf("Sorry, invalid choice!\n");
                    break;
                }
		}
	} while(choice!=4);
	
    return (0);
}
