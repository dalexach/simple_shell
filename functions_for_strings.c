#include "shell.h"
/**
* *_strncpy - copies a string
*@dest: string dest
*@src: origin to copy
*@n: number of bytes
*Return: dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i, l = 0;

	for (i = 0; (i != n && src[i] != '\0'); i++)
	{
		dest[l] = src[i];
		l++;
	}
	while (l != n)
		dest[l++] = '\0';
	return (dest);
}

/**
* _strlen - returns the lenght of a string
*@s: poiter of character
*Return: the length of a string
*/
int _strlen(char *s)
{
	int len;

	len = 0;
	while (*(s + len) != '\0')
		len++;
	return (len);
}

/**
* _strcmp - compares two strings
*@s1: string 1
*@s2: string 2
*Return: 0 for not equal, 1 if equal
*/
int _strcmp(char *s1, char *s2)
{
	int n;

	for (n = 0; s1[n] != '\0'; n++)
	{
		if (s1[n] > s2[n])
			return (0);
	}
	return (1);
}
