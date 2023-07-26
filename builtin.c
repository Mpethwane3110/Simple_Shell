#include "shell.h"
#include <stdlib.h>

/**
 * _myexit - function that will exit shell
 * @info: the strctr containing number of arguments
 *  Return: returns exit status
 */

int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Wrong number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current dir
 * @info: the strctr containing args
 *  Return: 0
 */
int _mycd(info_t *info)
{
	char *curr_dir, *dir, buffer[1024];
	int chdir_ret;

	curr_dir = getcwd(buffer, 1024);
	if (!curr_dir)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(curr_dir);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "cannot cd to: ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - cd current dir
 * @info: the strct with no. of args
 *  Return: 0
 */

int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help. Implement function \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
