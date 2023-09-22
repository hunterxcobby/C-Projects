#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>

void display_menu(void);
void operations(void);
int add(int count, ...);
int sub(int count, ...);
int multiply(int count, ...);
double divide(int count, ...);
int askContinue(void);
double mixed(int count, ...);
void mixed_operations(void);

#endif
