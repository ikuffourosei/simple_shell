#include "simpleshell.h"

/**
 *_issetenv - checks if a command line input is "setenv"
 * @command: input to be checked
 * Return: setenv value or -1 if failed
 */
int _issetenv(const char *command)
{
	char *tokens[4];
	int num_tokens;

	if (_strncmp(command, "setenv", 6) == 0)
	{
		num_tokens = tokenize(command, tokens, 4);

        if (num_tokens == 4)
	{
		return (_setenv(tokens[1], tokens[2], atoi(tokens[3])));
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
