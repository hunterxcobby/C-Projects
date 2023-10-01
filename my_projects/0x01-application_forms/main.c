#include "main.h"

int main(void)
{
    /*int num;
    char word[MAX_NAME_LENGTH];*/

  while (1) 
  {
    /* Display Infos*/
    mode_msg();
    title_msg();

    /*printf("First Name: ");
    fgets(word, sizeof(word), stdin);

    printf("Please enter your Age: ");
    scanf("%d", &num);*/
    
    /* Clear the input buffer*/
    /*while (getchar() != '\n');*/

    /*printf("Are these informations provided true?\n NAME: %s\n AGE: %d\n", word, num);
    printf("YES or NO? : ");
    fgets(word, sizeof(word), stdin);*/
    
    /** Remove the trailing newline character from the input*/
    /*word[strcspn(word, "\n")] = '\0';*/

    /* Check if the user answered "no" or anything other than "yes"*/
    /*if (strcmp(word, "yes") && strcmp(word, "YES") && strcmp(word, "Yes")) {
         printf("Please make sure to provide the correct details.\n\n");
   } else {
	   
	  break;exit the loop if the user answered "yes"
     }*/ 
      break;
   }

	printf("Great ! You will receive a confirmation message very soon.\n");


    return (0);
}

