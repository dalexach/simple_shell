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
	struct stat fileStat;
	int status, count = 0;

	buffer = NULL, length = 0;
	if (isatty(STDIN_FILENO))
                        write(STDOUT_FILENO, "$ ", 2);
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
			fork_fail();
		if (pid == 0)
		{
			/*execute the command*/
			_execve(buffer, characters, *commands, "/usr/bin", count, env);
		}
		else
		{
			wait(&status);
			/*free everithing*/
			if (commands == NULL)
				free_parent(buffer, commands);
			/**if exit, free everithing and exit the program*/
			else if (_strcmp("exit", commands[0]);
				free_exit(buffer, commands);
			/**free from the parent process*/
			else
				free_parent(buffer, commands);
		}
		length = 0, buffer = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	if (characters == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
