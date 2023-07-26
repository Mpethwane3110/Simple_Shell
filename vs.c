#include "shell.h"

/**
 * is_chain - check curr char in a chain delim
 * @info: the param buf
 * @p: ptr: curr position
 * @buf: char buf
 * Return: 1 in chain delim
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == ';')
		return (1);
	else if (buf[j] == '|' && buf[j + 1] == '|')
	{
	buf[j] = 0;
	j++;
	info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
	buf[j] = 0;
	j++;
	info->cmd_buf_type = CMD_AND;
	}
	else
	return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - status check if to continue chaining
 * @info: param struct
 * @p: ptr
 * @buf: buf
 * @i: beginning position
 * @len: length
 * Return: void
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j =  *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
	buf[i] = 0;
	j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
	if (!info->status)
	{
		buf[i] = 0;
	j = len;
	}
	}
	*p = j;
}

/**
 * replace_alias - fun replaces an alias in the tokenized string
 * @info: param struct
 * Return: if replaced 1. 0 if not replaced
 */

int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - fun that replaces vars in the tokenized string
 * @info: the param struct
 * Return: 1 if replaced, 0 if not
 */

int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - fun that replaces stng
 * @old: the address of old string
 * @new: point to the new string
 * Return: 1 if replaced, 0 if failed to replace
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
