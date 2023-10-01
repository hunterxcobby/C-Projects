#include "main.h"

int main(void)
{
  char firstName[50];
  char otherNames[50];
  char year[5];
  char month[5];
  char day[5];
    /*int num;
    char word[MAX_NAME_LENGTH];*/

  while (1) 
  {
    /* Display Infos for the mode */
    mode_msg();

    /* Wait for 2 seconds */
    sleep(2.3);

    /* Display Infos for the title */
    title_msg();

    /* Ask for details*/
    userName(firstName, otherNames);
    
    /* Birth Date*/
    void birthDate(year, month, day);
    printf("Date Of Birth: %s-%s-%s\n",month, day, year);
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

	/*printf("Well done, %s %s!\nYou will receive a confirmation message very soon.\n", otherNames, firstName);*/


    return (0);
}

