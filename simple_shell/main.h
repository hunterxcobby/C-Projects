#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *get_path(char *command);

extern char **environ;

/* for builtin*/
void builtin_cd(char *arg);
void builtin_exit();
void err_msg(char *command);

#endif 