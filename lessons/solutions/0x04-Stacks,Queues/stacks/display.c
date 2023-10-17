/**
 * display - Function to display the elements of the stack
 * Parameters:None
 * Returns:None
 */

void display()
{
	if(top == -1)
	{
		printf("Stack underflow\n"); /* Print error message if the stack is empty */
	}
	else if(top > 0)
	{
		printf("The elements of the stack are:\n"); /* Message to indicate stack elements are being displayed */
		for(i = top; i >= 0; i--) /* Loop to iterate through the elements from top to bottom */
		{
			printf("%d\n",stack[i]); /* Print each element */
		}
	}
}
