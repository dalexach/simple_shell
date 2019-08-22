#include "shell.h"

/**
 * main - Simple shell,
 * @argc: Argument counter
 * @argv: Argument vector
 * @env: Environment variables
 * Return: 1 if fails, 0 on exit
 */

int main(int argc, char **argv, char **env)
{
	char *buffer, **commands;
	size_t length;
	ssize_t characters;
	pid_t pid;
	int status, count = 0;

	buffer = NULL, length = 0;

	while ((characters = getline(&buffer, &length, stdin)))
	{
		if (characters = EOF)
		{
			if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			exit(0);
		}
		count++;
		commands = array_strtok(buffer);
		pid = fork();
		if (pid == -1)
			perror("Error:"), exit(EXIT_FAILURE);
		if (pid == 0)
		{
			/*execute the command*/
			printf("yes");
		}
		else
		{
			wait(&status);
			/*free everithing*/
		}
		length = 0, buffer = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	if (characters == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
