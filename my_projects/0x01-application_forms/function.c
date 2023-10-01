#include "main.h"

/* CENTER ALIGN*/
void centerAlignText(const char *text) 
{
    int padding;
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    padding = (w.ws_col - strlen(text)) / 2;
    printf("%*s%s\n", padding, "", text);
}

/* User's Name*/
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

/* Birth Date*/
void birthDate(int *year, int *month, int *day) 
{
    centerAlignText("BIRTH DATE");
    centerAlignText("========");

    printf("\033[1mMonth (MM): \033[0m");
    fgets(month, sizeof(month), stdin);
    monthInput[strcspn(month, "\n")] = '\0'; /* Remove newline*/

    if (strlen(month) >= 2) {
        fprintf(stderr, "Invalid format!\nPlease try again.\n");
        return (-1);  // Indicate an error
    }

    /* Ask for Day*/
    printf("\033[1mYear (YYYY): \033[0m");
    fgets(day, sizeof(year), stdin);
    yearInput[strcspn(day, "\n")] = '\0';  /* Remove newline*/

    if (strlen(day) > 2) {
        fprintf(stderr, "Invalid input!\nPlease try again.\n");
        return (-1);
    }

    /* Asks for Year*/
    printf("\033[1mYear (YYYY): \033[0m");
    fgets(year, sizeof(year), stdin);
    year[strcspn(year, "\n")] = '\0';  /* Remove newline*/

    if (strlen(year) > 4) {
        fprintf(stderr, "Invalid format!\nPlease try again.\n");
        return (-1);
    }

    /* Convert strings to integers*/
    *year = atoi(year);
    *month = atoi(month);
    *day = atoi(day);
}