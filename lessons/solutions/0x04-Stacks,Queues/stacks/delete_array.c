/**
 * pop - Function to remove the topmost element from the stack
 * Parameters: None
 * Returns: None
*/
void pop()
{
	int element; /* Variable to store the popped element */

	/* Check if the stack is empty */
	if(top == -1)
	{
		printf("Stack underflow\n"); /* Print error message if the stack is empty */
	}
	else
	{
		element=stack[top]; /* Retrieve the topmost element */
		printf("The deleted item is %d\n",stack[top]); /* Print the element being removed */
		top--; /* Decrement the top to simulate element removal */
	}
}
