#include "shell.h"

/**
 * bfree - function for freeing a ptr and NULL the addrss
 * @ptr: address of freed ptr
 * Return: (1) if free or (0) otherwise
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
