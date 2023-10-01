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
    centerAlignText("BIRTH DATE");
    centerAlignText("========");

        while(1) {
        /* Ask for Month*/
        printf("\033[1mMonth (MM): \033[0m");
        scanf("%2s", month);

        if (strlen(month) != 2 || atoi(month) < 1 || atoi(month) > 12) {
            fprintf(stderr, "Invalid month format!\nPlease try again.\n");
            continue; 
        }

        *month = atoi(month);
        break;
    }

    while(1) {
        /* Ask for Day*/
        printf("\033[1mDay (DD): \033[0m");
        scanf("%2s", day);

        if (strlen(day) != 2 || atoi(day) < 1 || atoi(day) > 31)
        {
            fprintf(stderr, "Invalid day format!\nPlease try again.\n");
            continue;
        }

        *day = atoi(day);
        break;
    }

    while(1) {
        /* Ask for Year*/
        printf("\033[1mYear (YYYY): \033[0m");
        scanf("%4s", year);

        if (strlen(year) != 4 || atoi(year) < 1900 || atoi(year) > 9999) 
        {
            fprintf(stderr, "Invalid year format!\nPlease try again.\n");
            continue;
        }

        *year = atoi(year);
        break;
    }
}
