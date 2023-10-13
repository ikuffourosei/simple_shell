#include "simpleshell.h"


/* ENV CHECK */

/**
 * _isenv - function that check whether the first word in the
 * input array is the word "env"
 * @input: input array from user
 * @env_copy: copy of environmental variables
 * Return: 
 * - 0 (success)
 * - -1 (otherwise)
 */
int _isenv(char **input, char **env_copy)
{
	int i, j, count;
	char str[4] = "env";

	i = 0;
	j = 0;
	count = 0;

	while (input[0][j] != '\0')
		j++;
	if (j == 3)
	{
		while (i < 3)
		{
			if (input[0][i] == str[i])
				count++;
			i++;
		}
		if (count == 3)
		{
			_env(env_copy);
			return (0);
		}
	}
	return (-1);
}

/* CD CHECK */

/**
 * _iscd - function that check whether
 * the first word in the input array is the word "cd"
 * @input: input of user, array of pointers
 * @loop: loop count
 * @arg: arguments
 * @env_copy: copy of environment variables
 * Return: 
 * - 0 (success)
 * - -1 (otherwise)
 */
int _iscd(char **input, int loop, char *arg[], char **env_copy)
{
	int count, i;
	char str[] = "cd";

	count = 0;
	i = 0;
	while (input[0][i] != '\0')
	{
		if (i < 2)
		{
			if (input[0][i] == str[i])
				count++;
		}
		i++;
	}
	if (i == 2)
		count++;

	if (count == 3)
	{
		_cd(input, loop, arg, env_copy);
		return (0);
	}
	else if (count == 2)
	{
		_put_err(input, loop, 3, env_copy);
		return (0);
	}
	return (-1);
}

/* EXIT CHECK */

/**
 * _isexit - function that check whether
 * the first word in the input array is the word "exit"
 * @input: array of input from user 
 * @loop: loop counter
 * @line: input user (pointer)
 * @arg: arguments in input
 * @env_copy: copy of environmental variables
 * @result: complete input
 * Return: 0 (success) -1 (otherwise)
 */
int _isexit(char **input, int loop, char *line, char **arg, char **env_copy, char *result)
{
	int count, i, n, y;
	char str[] = "exit";

	count = 0;
	i = 0;
	n = 0;
	y = 0;
	for (n = 0; input[n] != NULL; n++)
		;
	for (y = 0; env_copy[y] != NULL; y++)
		;

	while (input[0][i] != '\0')
	{
		if (i < 4)
		{
			if (input[0][i] == str[i])
				count++;
		}
		i++;
	}
	if (i == 4)
		count++;

	if (count == 5)
	{
		_type(input, loop, line, n, arg, env_copy, y, result);
		return (0);
	}
	else if (count == 4)
	{
		_put_err(input, loop, 3, arg);
		return (0);
	}
	return (-1);
}

/* HELP CHECK */

/**
 * _ishelp -  function that check whether
 * the first word in the input array is the word "help"
 * @input: array of input from user
 * @loop: loop counter
 * @arg: arguments in input
 * @env_copy: copy of environmental variables
 * 
 * Return: 0 (success) -1 (otherwise)
 */
int _ishelp(char **input, int loop, char *arg[], char **env_copy)
{
	int i, count;
	char str[] = "help";
	i = 0;
	count = 0;

	while (input[0][i])
	{
		if (i < 4)
		{
			if (input[0][i] == str[i])
				count++;
		}
		i++;
	}
	if (i == 4)
		count++;

	if (count == 5)
	{
		_help(input, loop, arg, env_copy);
		return (0);
	}
	return (-1);
}
