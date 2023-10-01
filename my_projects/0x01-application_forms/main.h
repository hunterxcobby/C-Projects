#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 100

/* FOR TEXT FORMATTING */
void centerAlignText(const char *text);

/* FUnctions Declarations*/
void title_msg(void);

#endif