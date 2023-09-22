#include "main.h"

/* GLOBAL VARIBALES*/

int operation_choice;

/**
 * display_menu - to display the menu to the user
 *
 *
 * return: the menu display
 */

void display_menu(void)
{

	printf(">> Hello, Welcome to simple calculator\n");
	printf("\x1b[4mThis is the MENU of operations you can perform with me.\x1b[0m\n");
	printf("\n\x1b[4mPress:\x1b[0m\n");
	printf("1: for ADDITION\n");
	printf("2: for SUBTRACTION\n");
	printf("3: for MULTIPLICATION\n");
	printf("4: for DIVISION\n");
	printf("5: for MIXED OPERATIONS\n");	

}

/**
 * operations - the operationa choice the user made.
 *
 *
 * return: the operation the user selected
 */

void operations(void)
{
	int result;
	double quotient;
	int *numbers = NULL;
	double *num = NULL;
	int count = 0;
	int input;

	/* take the operation number from the user*/
	printf("\nEnter your choice here:\n");
	scanf("%d", &operation_choice);

	switch(operation_choice)
	{
		case 1:
			{
				printf("\n\x1b[4mADDITION\x1b[0m\n");

				/*take inputs from the user.*/
				/*int input;
				  int numbers[100]; 
				  int count = 0;*/

				printf("Enter numbers to add (add 0 when done):\n");	
				do {
					scanf("%d", &input);

					numbers = realloc(numbers, (count + 1) * sizeof(int));
					numbers[count++] = input;
				} while (input != 0);	
				
				if(count > 11)
				{
					printf("Sorry, you can only add ten numbers at a go.\n");
				}
				else
				{
					result = add(count, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8], numbers[9], numbers[10], 0);
					printf("Sum is: %d\n", result);
				}
				free(numbers);
				break;
			}
		case 2:
			{
				printf("\n\x1b[4mSUBTRACTION\x1b[0m\n");
				printf("Enter numbers to subtract (add 0 when done):\n");
				do {
					scanf("%d", &input);

					numbers = realloc(numbers, (count + 1) * sizeof(int));
					numbers[count++] = input;
				} while (input != 0);

				if(count > 11)
				{
					printf("Sorry, you can only subtract  ten numbers at a go.\n");
				}
				else
				{
					result = sub(count, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8], numbers[9], numbers[10], 0);
					printf("Difference is: %d\n", result);
				}
				free(numbers);
				break;
			}
		case 3:
			{
				printf("\n\x1b[4mMULTIPLICATION\x1b[0m\n");
				printf("Enter numbers to multiply (add 1 when done):\n");
                                do {
                                        scanf("%d", &input);

                                        numbers = realloc(numbers, (count + 1) * sizeof(int));
                                        numbers[count++] = input;
                                } while (input != 1);

                                if(count > 11)
                                {
                                        printf("Sorry, you can only multiply  ten numbers at a go.\n");
                                }
                                else
                                {
                                        result = multiply(count, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8], numbers[9], numbers[10], 1);
                                        printf("Product is: %d\n", result);
                                }
                                free(numbers);
                                break;
			}
		case 4:
			{
				printf("\n\x1b[4mDIVISION\x1b[0m\n");
				
				           printf("Enter numbers to divide (add 0 when done):\n");
                                do {
                                        scanf("%d", &input);

					if(input != 0)
					{
					
                                        	num = realloc(num, (count + 1) * sizeof(int));
						if (num == NULL)
						{
							printf("Memory allocation failed!\n");
							break;
						}

						num[count++] = input;
					}
                                } while (input != 0);

                                if(count <= 1)
                                {
                                        printf("At least two numbers are need for division.\n");
                                }
				else if (count > 11)
				{
					printf("Sorry you can only divide ten numbers at a go\n");
				}
                                else
                                {
                                        quotient = divide(count, num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8], num[9], num[10], 0);
					if (quotient == 0.0)
					{
						printf("Cannot divide by zero.\n");
					}
					else
					{
						printf("Quotient is: %.2f\n", quotient);
					}
                                }
                                free(num);
				break;
			}
		case 5:
			{
				printf("\n\x1b[4mMIXED OPERATIONS\x1b[0m\n");
				mixed_operations();
				break;

			}
		default:
			{
				printf("\n\x1b[4mInvalid Input\x1b[0m\n");
				printf("OPERATION %d: not found!\n", operation_choice);
			}
	}

}


