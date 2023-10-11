#include "simpleshell.h"

/**
 * puterror - function that prints an error character
 * @c: character
 * Return; integer value
 */
int puterror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
