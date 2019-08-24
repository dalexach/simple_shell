#include "shell.h"

/**
 * argv_check - Entry point
 * Description: Check status of argument in /bin/ and /usr/bin
 * @av0: First argument from user.
 * @f_av: Pointer to a full path of command.
 * @env: The environment variable.
 * Return: 0 if nothing found.
 */

int argv_check(char *av0, char *f_av, char **env)
{
        struct stat st;
        int i = 0, j = 0;
        char *str = NULL;

/* handle local functions */
        if (stat(av0, &st) == 0)
        {
                f_av = av0;
                return (1);
        }

        str = _getenv(env, "PATH");
        do {
                if (str[i] == ':' || str[i] == '\0')
                {
                        _strcat(f_av, "/");
                        _strcat(f_av, av0);
                        if (access(f_av, X_OK) == 0)
                                return (1);
                        _memset(f_av, 0, _strlen(f_av));
                        j = 0;
                }
                else
                        f_av[j++] = str[i];
        } while (str[i++] != '\0');
        return (0);
}

/**
 * built_in - Entry point
 * Description: Check for valid built_in function and run it.
 * @av: The arguments being passed.
 * @p_cwd: The name of the previous working directory.
 * @env: The environment variable.
 * @command: The program name, from argv[0].
 * @count: The count of times the program has looped.
 * Return: 1 if valid, else 0.
 */
int built_int(char **av, char *p_cwd, char **env, char *command, int count)
{
        long i = 0;
        int j = 0, ret_val = 0, flag;

        if (_strcmp(av[0], "cd") == 0)
        {
                ret_val = ch_dir(av[1], p_cwd, env, command, count, av);
                free(av);
                if (ret_val == 2)
                        return (2);
                return (1);
        }
        if ((_strcmp(av[0], "exit") == 0) && (av[1] == NULL))
        {
        //      helper(av);
                exit(0);
        }
        else if ((_strcmp(av[0], "exit") == 0) && (av[1] != NULL))
        {
                i = _stoi(av[1]);
                if (i > INT_MAX || i < 0)
                {
                        flag = 1;
                        message_error(av, command, count, flag);
                        free(av);
                        return (2);
                }
                else if (i >= 0)
                {
                        //helper(av);
                        exit(i);
                }
        }
        if (_strcmp(av[0], "env") == 0)
        {
                j = 0;
                while (env[j])
                {
                        flag = 2;
                        message_error(av, command, count, flag);
                        write(STDOUT_FILENO, env[j], _strlen(env[j]));
                        write(STDOUT_FILENO, "\n", 1);
                        j++;
                }
                free(av);
                return (1);
        }
        return (0);
}

_getenv (){
}

string_mod (){
}
