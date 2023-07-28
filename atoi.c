#include "shell.h"

/**
 * interactive - fun that checks if the shell is in interactive mode
 * @info: struct pointer with args
 * Return: in interactive mode returns (1) if not return (0)
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - functn that checks if character is a delimeter
 * @c: the character to be checked
 * @delim: character is equal to the character to check
 * Return: (1) if the character (char) is a delim or (0) if not
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - function that checks if the character is alphabetic(char)
 *@c: the character we checking
 *Return: (1) if the character is alphabetic, (0) if the character is a no.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - function that converts a string to an integer(number)
 *@s: the string we converting
 *Return: (0) if no numbers in string, the converted number otherwise
 */

int _atoi(char *s)
{
	int index, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (index = 0;  s[index] != '\0' && flag != 2; index++)
	{
		if (s[index] == '-')
			sign *= -1;

		if (s[index] >= '0' && s[index] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
