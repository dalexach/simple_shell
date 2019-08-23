#include "shell.h"

/**
 * fork_fail - function that handles a fork fail
 * Return: Nothing
*/

void fork_fail(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}

/**
 * message_error - prints a error message
 * @av: vector of commands
 * @command: command not found
 * @count: counter of times the loop has been executed
 * Return: Nothing.
*/

void message_error(char **av, char *command, int count)
{
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", 2);
	_putchar(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
}
