#include "main.h"

/* Display Model Infos*/
void mode_msg(void)
{
    centerAlignText("--- ONLINE REGISTRATION FORM TEMPLATE ---\n");
    printf("This is for learning purpose and no info will be saved.\n");
    printf("--------------------------------------------------------\n");
    printf("RELEASE DATE: \033[2m01-08-2023\033[0m\n");
    printf("RELEASE TIME: \033[2m20:09:30 GMT\033[0m\n");
    printf("AUTHOR: Cobby Sefah \033[2m<@hunterxcobby>\033[0m\n");
    printf("--------------------------------------------------------\n\n\n\n");
}

/* Display Message*/
void title_msg(void)
{
    centerAlignText("ABC REGISTRATION FORMS");
    centerAlignText("======================");


    printf("\nPlease fill out the form for registration.\n");
    printf("Kindly make sure to provide only your valid details.\n\n");
}

/* The User's Name*/
void userName(char *firstName, char *otherNames) 
{
    centerAlignText("NAMES");
    centerAlignText("=====");

    printf("\033[1mFirst Name: \033[0m");
    fgets(firstName, sizeof(firstName), stdin);
    firstName[strcspn(firstName, "\n")] = '\0';/* Remove newline*/

    /* Check if first name exceeds limit*/
    if(strlen(firstName) >= 50) 
    {
        fprintf(stderr, "Name limit exceeded!\nPlease start over.\n");
        exit(0);
    }

    printf("\033[1mLast Name: \033[0m");    
    fgets(otherNames, sizeof(otherNames), stdin);
    otherNames[strcspn(otherNames, "\n")] = '\0';  /* Remove newline*/

    if(strlen(otherNames) >= 50) {
        fprintf(stderr, "Name limit exceeded!\nPlease start over.\n");
        exit(0);
    }
}