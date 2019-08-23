#include "shell.h"
/**
 * free_all - frees all the memory including a double pointer
 * @ptr: pointer to free
 * Return: Nothing
*/

void free_all(char **ptr)
{
	unsigned int i = 0;

	if (ptr == NULL)
		return;

	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}

	if (ptr[i] == NULL)
		free(ptr[i]);
	free(ptr);
}

/**
 * free_parent - free the buffer and the commands
 * @buffer: buffer in getline
 * @commands: double pointer that store all the commands inserted
 * Return: Nothing(void)
*/

void free_parent(char *buffer, char **commands)
{
	free(buffer);
	free_all(commands);
}

/**
 * free_exit - free the buffer and the commands and exit form the console
 * @buffer: buffer in getline
 * @commands: double pointer that store all the commands inserted
 * Return: Nothing(void)
*/

void free_exit(char *buffer, char **commands)
{
	free(buffer);
	free_all(commands);
	exit(EXIT_SUCCESS);
}
