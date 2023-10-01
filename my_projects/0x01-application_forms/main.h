#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100

/* FOR TEXT FORMATTING */
void centerAlignText(const char *text);

/* FUnctions Declarations*/
void mode_msg(void);
void title_msg(void); 
void userName(char *firstName, char *otherNames);
void birthDate(int *year, int *month, int *day);


#endif