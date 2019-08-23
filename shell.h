#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/**find_command.c*/
unsigned int length_of_command(char *string);
char **array_strtok(char *str);

/**functions_for_strings.c*/
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

/**free_all.c*/
void free_all(char **ptr);

/**process_functions.c*/
void path_e(char **commands, char *buffer, char **env, char **argv, int count);

/**error_messages.c*/
void fork_fail(void);
void message_error(char **av, char *command, int count);

/**_putchar.c*/
int _putchar(char c);

#endif /* shell */
