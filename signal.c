#include "simpleshell.h"

/**
 * _signal - Function that handles SIGINT signal
 * @sig: the signal to catch
 */
void _signal(int sig)
{
	/* Indicating that it is unintentionally used*/
	(void)sig;

	_putchar('\n');
	_print("#cisfun$ ");
}
