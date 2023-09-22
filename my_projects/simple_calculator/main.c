#include "main.h"

/* GLOBAL VARIABLES*/


int main(void)
{
        char choice;

        while(1)
        {
                /*DISPLAY MENU TO THE USER*/
                display_menu();

                /* OPERATIONS*/
                operations();

		/* MIXED OPRATIONS*/
		/*mixed_operations();*/

                /* QUIT OR CONTINUE*/
                choice = askContinue();
                if (choice == 'y' || choice == 'Y')
                {
                        continue;
                }
                else
                {
                        printf("BYE !\n");
                        exit(0);
                }


        }

        return(0);
}
