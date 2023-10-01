#include "main.h"

int main(void)
{
  char firstName[50];
  char otherNames[50];
  char year[5];
  char month[3];
  char day[3];
  int sirOrMadam;
  char gender[20];

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
    birthDate(year, month, day);

    /* Ask for gender */
    genderChoice(gender);

    /* Saultion*/
    if (strcmp(gender, "Male") == 0) 
    {
    printf("I am glad you are a Gentleman, %s!\n", otherNames);
} else if (strcmp(gender, "Female") == 0) {
    printf("I am glad you are a Lady, %s!\n", otherNames);
} else {
    printf("I am glad you are %s, %s!\n", gender, otherNames);
}

    return (0);
}

