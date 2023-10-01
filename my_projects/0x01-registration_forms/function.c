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

    printf("\n\033[1mOther Names: \033[0m");    
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
    centerAlignText("==========");

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
        printf("\n\033[1mDay (DD): \033[0m");
        scanf("%2s", day);

        /*Consume the newline character*/
        while (getchar() != '\n');

        if (strlen(day) != 2 || atoi(day) < 1 || atoi(day) > 31) {
            if (showError) {
                fprintf(stderr, "\033[A\033[K");  /*Clear previous error message*/
            }
            showError = 1;
            fprintf(stderr, "Invalid day format!\n\n");
            continue;
        }

        *day = atoi(day);
        break;
    }

    showError = 0;

    while(1) {
        /* Ask for Year*/
        printf("\n\033[1mYear (YYYY): \033[0m");
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

    showError = 0;

        break;
    }

    /*printf("\nDate Of Birth: %s %s %s\n",month, day, year);*/
 
}


/* Ask user for gender*/
void genderChoice(char* gender) 
{
    int choice;
    
    centerAlignText("GENDER");
    centerAlignText("======");

    printf("\n\033Please select your gender by entering the corresponding number:\n\n");
    printf("\033[1m\n1. Male\n\n2. Female\n\n3. Specify\n\n4. Rather not say\033[0m\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) 
    {
        strcpy(gender, "Male");
    } 
    else if (choice == 2) 
    {
        strcpy(gender, "Female");
    } 
    else if (choice == 3) 
    {
        printf("\nPlease specify your gender: \n");
        scanf("%s", gender);
        strcpy(gender, "Sir/Madam");
    }
    else if (choice == 4) 
    {
        printf("\nAlright then, keep your secrets ;) \n\n");
        strcpy(gender, "Sir/Madam");
    } 
    else 
    {
        printf("Invalid choice!\n");
    }
}


/* Ask for address*/
void askAddress(void)
{
    
    char country[100];
    char city[50];
    char street_name[50];

    centerAlignText("ADDRESS");
    centerAlignText("=======");

    printf("\n\033[1mCountry: \033[0m");
    scanf("%s", country);

    printf("\n\033[1mCity: \033[0m");
    scanf("%s", city);

    printf("\n\033[1mStreet Address: \033[0m");
    scanf("%s", street_name);

    printf("\n\n");
}

/* Ask for contact*/
void askContact(char *phone, char *mail)
{
    centerAlignText("CONTACT");
    centerAlignText("=======");

    printf("\n\033[1mTelephone No. : \033[0m");
    scanf("%s", phone);

    printf("\n\033[1mEmail Address: \033[0m");
    scanf("%s", mail);

    printf("\n");
}