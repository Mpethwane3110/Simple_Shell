#include "shell.h"

/**
 * bfree - fun to free a ptr and NULLs the addrss
 * @ptr: address of ptr to be freed
 * Return: 1 if free or 0 otherwise
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
