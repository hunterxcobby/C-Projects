#include "main.h"

/* Display Model Infos*/
void mode_msg(void)
{
    centerAlignText("--- ONLINE REGISTRATION FORM TEMPLATE ---\n");
    printf("This is for learning purpose and no info will be saved.\n");
    printf("--------------------------------------------------------\n");
    printf("RELEASE DATE: 01-08-2023\n");
    printf("RELEASE TIME: 20:09:30 GMT\n");
    printf("AUTHOR: Cobby Sefah <solomonsefah13@gmail.com>\n");
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
int userName(void) 
{
    char firstName[50];
    char otherNames[50];

    centerAlignText("NAME");
    centerAlignText("====");

    printf("\nFirst Name: ");
    fgets(firstName, sizeof(firstName), stdin);
    firstName[strcspn(firstName, "\n")] = '\0';/* Remove newline*/

    /* Check if first name exceeds limit*/
    if(strlen(firstName) >= 50) 
    {
        fprintf(stderr, "Name limit exceeded!\nPlease start over.\n");
        exit(0);
    }

    printf("Other Names: ");
    fgets(otherNames, sizeof(otherNames), stdin);
    otherNames[strcspn(otherNames, "\n")] = '\0';  /* Remove newline*/

    if(strlen(otherNames) >= 50) {
        fprintf(stderr, "Name limit exceeded!\nPlease start over.\n");
        exit(0);
    }

    return(0);
}