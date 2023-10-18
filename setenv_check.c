#include "simpleshell.h"

/**
 *_issetenv - checks if a command line input is "setenv"
 * @command: input to be checked
 * Return: setenv value or -1 if failed
 */
int _issetenv(char *command)
{
	char *tokens[3];
	int num_tokens;

	if (_strncmp(command, "setenv", 6) == 0)
	{
		num_tokens = tokenize(command, tokens, 3);

		if (num_tokens >= 3)
		{
			return (_setenv(tokens[1], tokens[2], 1);
		}
		else if (num_tokens == 2)
		{
			return _setenv(tokens[1], "", 1);
		}
		else
		{
			printerror("Usage: setenv NAME VALUE\n");
			return (-1);
		}
	}
	else
	{
		printerror("Command not recognized\n");
		return (-1);
	}
}
