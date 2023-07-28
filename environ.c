#include "shell.h"

/**
 * _myenv - function that prints the current environment
 * @info: struct with no. of args
 * Return: returns zero
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: struct for arguments
 * @name: the environmnt variable name
 * Return: the value
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *env_node = info->env;
	char *p;

	while (env_node)
	{
	p = starts_with(env_node->str, name);
	if (p && *p)
		return (p);
	env_node = env_node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - function that nitializes a new environment variable
 * @info: Structure containing potential arguments
 *  Return: Always 0
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - funct to remove an environment var
 * @info: the structure containing potential args
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int index;

	if (info->argc == 1)
	{
		_eputs("Few arguments.\n");
		return (1);
	}

	for (index = 1; index <= info->argc; index++)
	{
			_unsetenv(info, info->argv[index]);
	}
	return (0);
}

/**
 * populate_env_list - function that populates env linked list
 * @info: structure with the potential no. argumnts
 * Return: Always 0
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
