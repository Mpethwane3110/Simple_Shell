#include <stdlib.h>
#include "shell.h"

/**
 * _myhistory - displa\ing the hist. list
 * @info: the strct with the no. of args
 *  Return: (0)
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to strng
 * @info: parameter struct
 * @str: the string alias
 * Return: (0) on success, (1) on unsucess
 */

int unset_alias(info_t *info, char *str)
{
	char *alias_name, c;
	int ret;

	alias_name = _strchr(str, '=');
	if (!alias_name)
		return (1);
	c = *alias_name;
	*alias_name = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*alias_name = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: (0) on success, (1) if unsuccessful
 */

int set_alias(info_t *info, char *str)
{
	char *alias_name;

	alias_name = _strchr(str, '=');
	if (!alias_name)
		return (1);
	if (!*++alias_name)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - fun prints the alias string
 * @node: the alias node
 * Return: (0) if successful, (1) if unsuccessful
 */

int print_alias(list_t *node)
{
	char *alias_name = NULL, *a = NULL;

	if (node)
	{
		alias_name = _strchr(node->str, '=');
		for (a = node->str; a <= alias_name; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(alias_name + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - fun that mimics the alias cmd builtin
 * @info: the strct no. of args
 *  Return: (0)
 */

int _myalias(info_t *info)
{
	int i = 0;
	char *alias_name = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		alias_name = _strchr(info->argv[i], '=');
		if (alias_name)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
