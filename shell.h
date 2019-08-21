#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>

/**find_command.c*/
unsigned int length_of_command(char *string);
char **array_strtok(char *str);

#endif /* shell */
