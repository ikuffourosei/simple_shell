#include "simpleshell.h"

/**
 * tokenize - function that splits a command line into individual tokens
 * @command: command paramter
 * @tokens: tokens paramter
 * @max_tokens: max number of tokens
 * Return: token_counts (int value)
 */
int tokenize(char *command, char *tokens[], int max_tokens)
{
	char *token;
	char *delim[] = " ,()";
	int token_count = 0;

	if (command == NULL)
		return (0);
	token = _strtok(command, delim);
	while (token != NULL)
	{
		if (token_count < max_tokens)
		{
			tokens[token_count] = token;
			token_count++;
			token = _strtok(NULL, delim);
		}
		else
		{
			break;
		}
	}
	return (token_count);
}
