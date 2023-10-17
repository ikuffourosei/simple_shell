#include "simpleshell.h"

/**
 * _putchar - Function that prints a character to the STDOUT
 * @c: character to be printed
 * Return: int value
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
