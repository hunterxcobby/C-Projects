#include "main.h"

int main(void)
{
  char firstName[50];
  char otherNames[50];
  char year[5];
  char month[3];
  char day[3];
  char gender[20];
  char phone[15];
  char mail[20];
  int choice;

  
    /* Display Infos for the mode */
    mode_msg();

while (1) 
  {
    /* Wait for 2 seconds */
    sleep(2.3);

    /* Display Infos for the title */
    title_msg();

    /* Ask for details*/
    userName(firstName, otherNames);
    
    /* Birth Date*/
    birthDate(year, month, day);

    /* Ask for gender */
    genderChoice(gender);

    /*Ask for address*/
    askAddress();

    /* Ask for COntact*/
    askContact(phone, mail);

    sleep(2);
    /* Salution*/
    if (strcmp(gender, "Male") == 0) 
    {
    printf("Well done Sir, %s!\n", otherNames);
    } 
    else if (strcmp(gender, "Female") == 0) 
    {
    printf("Well done Miss, %s!\n", otherNames);
    } 
    else 
    {
    printf("Well done %s, %s!\n\n", gender, otherNames);
    }

    /* SUBMISSION*/
    choice = submitOrCorrect();

    if (choice == 1)
    {
        sleep(1.5);
        break;
    } 
    else if (choice == 2) 
    {
        sleep(2.3);
        printf("Please make the necessary corrections.\n");
        continue;
    } 
    else 
    {
        printf("Invalid choice. Please try again.\n");
        continue;
    }

   break;
  }

  /* Contact*/
  printf("Your forms have been submitted.\n");
  printf("We will keep you updated via.\n");
  printf("\033[1mSMS :\033[0m%s", phone);
  printf("\n\033[1mEmail :\033[0m%s\n", mail);

    return (0);
}

