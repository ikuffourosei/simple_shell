#include "simpleshell.h"

/**
 * _issetenv - Check if a command line input is "setenv" and set an environment variable.
 * @command: The input command to be checked.
 * Return: 0 on success, -1 on failure.
 */
int _issetenv(char *command)
{
    char *tokens[3];
    int num_tokens;

    if (_strncmp(command, "setenv", 6) == 0)
    {
        num_tokens = tokenize(command, tokens, 3);

        if (num_tokens == 3)
        {
            return _setenv(tokens[1], tokens[2], 1);
        }
        else if (num_tokens == 2)
        {
            return _setenv(tokens[1], "", 1);
        }
        else
        {
            printerror("Usage: setenv NAME VALUE");
	    puterror('\n');
            return (-1);
        }
    }
    else
    {
         return (-1);
    }
}
