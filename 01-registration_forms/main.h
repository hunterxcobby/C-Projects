#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

/* FOR TEXT FORMATTING */
void centerAlignText(const char *text);

/* FUnctions Declarations*/
void mode_msg(void);
void title_msg(void); 
void userName(char *firstName, char *otherNames);
void birthDate(char *year, char *month, char *day);
void genderChoice(char* gender);
void askAddress(void);
void askContact(char *phone, char *mail);
int submitOrCorrect(void); 

#endif