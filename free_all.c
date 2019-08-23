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

void free_parent(char *buffer, char **commands)
{
	free(buffer);
	free_all(commands);
}

void free_exit(char *buffer, char **commands)
{
	free(buffer);
	free_all(commands);
	exit(EXIT_SUCCESS);
}
