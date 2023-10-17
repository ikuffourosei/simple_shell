#include "simpleshell.h"

/**
 * _print - function that prints a string
 * @str: pointer to first character of string
 */
int _print(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		_putchar(str[count]);
		count++;
	}
	return (count);
}
