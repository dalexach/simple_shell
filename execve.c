#include "shell.h"
/**
 * _execve - Entry point
 * Description: Execute's program. All programs located in
 * /bin/ /usr/bin, and the functions cd, exit, env.
 * @buffer: A string of arguments.
 * @ncr: Number of character reading.
 * @command: The name of the program, from argv[0].
 * @p_cwd: Name of the previous working directory.
 * @count: Count of times the loop has been executed.
 * @env: The enviornment variable.
 * Return: Returns 0 on success. 1 if there's an error.
 */
int _execve(char *buffer, int ncr, char *command, char *p_cwd, int count, char **env)
{
	char f_av[100] = {'\0'}, **av = NULL;
	pid_t pid;
	int n = string_m(buffer), built_in_ret;
	if (ncr == -1)
		return (1);
	av = malloc(sizeof(char *) * (n + 1));
	if (av == NULL)
		return (1);
	string_split(buffer, av, ncr);
	/* check if local program or other built-in func*/
	built_in_ret = built_in(av, p_cwd, env, command, count);
	if (built_in_ret == 1)
		return (0);
	else if (built_in_ret == 2)
		return (2);
	/* check if the command located in PATH */
	_strcpy(f_av, av[0]);
	if (argv_check(av[0], f_av, env) == 0)
	{
		write(STDERR_FILENO, command, _strlen(command));
		write(STDERR_FILENO, ": ", 2);
		print_num(count);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "not found\n", 10);
		return (127);
	}
		pid = fork();
	if (pid == -1)
	{
		free(av);
		perror("fork Error:");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(f_av, av, NULL) == -1)
		{
			write(STDERR_FILENO, name, _strlen(name));
			write(STDERR_FILENO, ": ", 2);
			print_num(count);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "not found\n", 10);
			free(av);
			exit(0);
		}
	}
	else
		wait(NULL);
	free(av);
	return (0);
}
