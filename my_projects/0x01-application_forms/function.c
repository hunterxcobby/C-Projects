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
void birthDate(char *year, char *month, char *day) 
{
    int showError;

    centerAlignText("BIRTH DATE");
    centerAlignText("========");

    showError = 0;  /*Flag to track whether an error message has been displayed*/

    while(1) 
    {
        /* Ask for Month*/
        printf("\033[1mMonth (MM): \033[0m");
        scanf("%2s", month);

        /* Consume the newline character*/
        while (getchar() != '\n');

        if (strlen(month) != 2 || atoi(month) < 1 || atoi(month) > 12) {
            if (showError) {
                fprintf(stderr, "\033[A\033[K");  /* Clear previous error message*/
            }
            showError = 1;
            fprintf(stderr, "Invalid month format!\n\n");
            continue; 
        }

        *month = atoi(month);
        break;
    }

    showError = 0;  /*Reset the flag*/

    while(1) {
        /* Ask for Day*/
        printf("\033[1mDay (DD): \033[0m");
        scanf("%2s", day);

        /*Consume the newline character*/
        while (getchar() != '\n');

        if (strlen(day) != 2 || atoi(day) < 1 || atoi(day) > 31) {
            if (showError) {
                fprintf(stderr, "\033[A\033[K");  /*Clear previous error message*/
            }
            showError = 1;
            fprintf(stderr, "Invalid day format!\nPlease try again.\n\n");
            continue;
        }

        *day = atoi(day);
        break;
    }

    showError = 0;

    while(1) {
        /* Ask for Year*/
        printf("\033[1mYear (YYYY): \033[0m");
        scanf("%4s", year);

        /*Consume the newline character*/
        while (getchar() != '\n');

        if (strlen(year) != 4 || atoi(year) < 1900 || atoi(year) > 9999) {
            if (showError) {
                fprintf(stderr, "\033[A\033[K");  /*Clear previous error message*/
            }
            showError = 1;
            fprintf(stderr, "Invalid year format!\n\n");
            continue;
        }

        *year = atoi(year);
        break;
    }
}
