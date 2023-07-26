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
	int index, i;
	char *s = dest;

	index = 0;

	while (src[index] != '\0' && index < n - 1)
	{
		dest[index] = src[index];
		index++;
	}
	if (index < n)
	{
		index = i;
		while (index < n)
		{
			dest[index] = '\0';
			index++;
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
	int index, j;
	char *s = dest;

	index = 0;
	j = 0;

	while (dest[index] != '\0')
		index++;
	while (src[j] != '\0' && j < n)
	{
		dest[index] = src[j];
		index++;
		j++;
	}
	if (j < n)
		dest[index] = '\0';
	return (s);
}

/**
 *_strchr - function to locate a character in a string
 *@string: the string to be parsed
 *@c: the character to locate
 *Return: ptr
 */

char *_strchr(const char *string, char c)
{
	do {
		if (*string == c)
			return(string);
	} while (*string++ != '\0');

	return (NULL);
}
