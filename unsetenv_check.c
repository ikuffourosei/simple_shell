#include "simpleshell.h"

/**
 * _isunsetenv - check if a command line input is "unsetenv" and call _unsetenv
 * @command: The input to be checked
 * @env_copy: Copy of the environmental variables
 * @j: Number of elements in env_copy
 * @arg: argument
 * Return: 0 if the input is "unsetenv"
 * -1 otherwise
 */
int _isunsetenv(char *command, char **env_copy, int *j, char **arg)
{
	if (_strncmp(command, "unsetenv", 8) == 0)
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
