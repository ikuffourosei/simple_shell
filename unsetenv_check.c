#include "simpleshell.h"

/**
 * _isunsetenv - Check if a command line input is "unsetenv" and call _unsetenv
 * @command: The input to be checked
 * @env_copy: Copy of the environmental variables
 * @j: Number of elements in env_copy
 * Return: 0 if the input is "unsetenv"
 * -1 otherwise
 */
int _isunsetenv(char *command, char **env_copy, int *j)
{
	if (_strcmp(command, "unsetenv") == 0)
	{
		if (arg[1] != NULL)
		{
			if (_unsetenv(arg[1]) == 0)
			{
				return (0);
			}
			else
			{
				printerror("Failed to unset the environmental variable\n");
			}
		}
		else
		{
			printerror("Usage: unsetenv VARIABLE_NAME\n");
		}
	}
	return (-1);
}
