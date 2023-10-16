#include "simpleshell.h"

/**
 * _builtinerr - function that writes the error
 * Description: identifies and handles specific errors
 * related to built-in commands in your shell program
 *
 * @input: array of input accepted from user
 */
void _builtinerr(char **input)
{
	int i, j, n, count;
	char str1[5] = "exit", str2[2] = "cd", str3[5] = "help";

	i = 0;
	j = 0;
	n = 0;
	count = 0;

	while (input[0][j] != '\0')
		j++;
	if (j == 2)
	{
		for (; i < 2; i++)
			if (input[0][i] == str2[i])
				count++;
		if (count == 2)
			_errorcd(input);
	}
	if (j == 4)
	{
		for (i = 0 ; i < 4; i++)
			if (input[0][i] == str1[i])
				count++;
		if (count == 4)
			_errorexit(input);
		for (i = 0; i < 4; i++)
			if (input[0][i] == str3[i])
				n++;
		if (n == 4)
			_errorhelp(input);
	}
}

/**
 * _builtinerr2 - function that writes the error
 * Description: Similar to the above function but this function
 * checks the command name in 'input[0]'
 * and compares it to specific built-in command names
 * "unsetenv" and "setenv."
 *
 * @input: input pointer
 */
void _builtinerr2(char **input)
{
	int i, j, count;
	char str1[7] = "setenv", str2[9] = "unsetenv";

	i = 0;
	j = 0;
	count = 0;

	while (input[0][j] != '\0')
		j++;
	if (j == 6)
	{
		for (; i < 6; i++)
			if (input[0][i] == str1[i])
				count++;
		if (count == 6)
			_errorenv(input);
	}
	if (j == 8)
	{
		for (; i < 8; i++)
			if (input[0][i] == str2[i])
				count++;
		if (count == 8)
			_errorenv(input);
	}
}
