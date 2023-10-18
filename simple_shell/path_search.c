#include "main.h"

/**
 * This contains codes
 * for searching through
 * the path 
 */

char *get_path(char *command) /* It takes the tokenized string as argument and calls it a command*/
{
  char *path = getenv("PATH");
  char *path_copy = strdup(path);
  char command_path[1024];
  char *dir = strtok(path_copy, ":");
  
  /*if (path_copy == NULL)
  {
    return (NULL);
  }*/

  
  while (dir != NULL) 
  {
    
    strcpy(command_path, dir);
    
    if (command_path[strlen(command_path) - 1] != '/')
    {
      strcat(command_path, "/");
    }

    strcat(command_path,command);

    if (access(command_path, X_OK) == 0)
    {
      free(path_copy);
      return (strdup(command_path));
    }

    dir = strtok(NULL, ":");
  }
  free(path_copy);
  return (command);
}