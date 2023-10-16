#include "simpleshell.h"

/**
 * search_str - checks if a character parameter is inside a string
 * @str: string parameter
 * @c: character being checked
 * Return: 1 (success) 0 (otherwise)
 */
int void _check(char *str, char c)
{
	int count = 0;

	while (str[count] != '\0')
	{
		if (str[count] == c)
		{
			break;
		}
		count++;
	}
	if (str[count] == c)
		return (1);
	else
		return (0);
}
