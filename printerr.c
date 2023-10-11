#include "simpleshell.h"

/**
 * print_error - prints the error to the STDOUT
 * @str: string parameter
 * Reyurn: integer value
 */
int printerror(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		puterror(str[count]);
		count++
	}
	return (count);
}
