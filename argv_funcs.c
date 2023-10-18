#include "simpleshell.h"

/**
 *cui - Check User Input and determine which command
 *@input: array of input tokens
 *@loop: loop counter
 *@iu: input user
 *@arg: arguments in input
 *@env_copy: copy of environmental variable
 *@j: number of elements in env_copy
 *@result: complete input of user
 * Return: -1 if the input is neither env nor cd
 *or 0 if the input is a recognized command
 */
int cui(char **input, int loop, char *iu, char **arg, char ***env_copy,\
		int *j, char *result)
{
	int help = 0, cd = 0, ex = 0, env = 0, unset = 0, set = 0;

	help = _ishelp(input, loop, arg, *env_copy);
	cd = _iscd(input, loop, arg, *env_copy);
	ex = _isexit(input, loop, iu, arg, *env_copy, result);
	env = _isenv(input, *env_copy);
	unset = _isunsetenv(input[0], *env_copy, j, arg);
	set = _issetenv(arg[0]);
	if (help == 0)
		return (help);
	if (cd == 0)
		return (cd);
	if (ex == 0)
		return (ex);
	if (env == 0)
		return (env);
	if (unset == 0)
		return (unset);
	if (set == 0)
		return (set);
	return (-1);
}

/**
 * shfunc- this function is the core of the shell and
 * responsible for executing commands
 *@line: input command of user
 *@loop: loop count
 *@argv: argumnets vector
 *@env_copy: copy of environment variables
 *@j: number of elements in env_copy
 *@result: complete input
 */
void shfunc(char *line, int loop, char *argv[], char ***env_copy, int *j, char *result)
{
	char **arg = NULL;
	int ind, res;

	line = _comments(line);
	arg = parsing(line);
	res = 1;
	ind = 0;
	if (arg)
	{
		for (ind = 0; arg[ind] != NULL; ind++)
			;
		res = cui(arg, loop, line, argv, env_copy, j, result);
		if (res != 0)
		{
			arg = check_path(arg, *env_copy);
			if (arg)
				foork(arg, line, ind, loop, argv, *j, *env_copy, result);
		}
		free_grid(arg, ind);
		free(line);
	}
	else
	{
		free(line);
		fflush(STDIN_FILENO);
	}
	_put_err(arg, loop, 0, argv);
}
