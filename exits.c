#include "shell.h"

/**
 **_strncpy - function that copies a string
 *@dest: where the string is being copied to
 *@src: where the string came from
 *@n: the number of characters to be copied
 *Return: string
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - function to concatenate 2 strings
 *@dest: the 1st string
 *@src: the 2nd string
 *@n: the number of bytes used
 *Return: string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}


/**
 *_strchr - function to locate a character in a string
 *@s: the string to be parsed
 *@c: the character to locate
 *Return: ptr
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
