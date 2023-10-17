#include "simpleshell.h"

/**
 * _signal - Function that handles SIGINT signal
 * @sig: the signal to catch
 */
void _signal(int sig)
{
	(void)signal;

	_putchar('\n');
	_print("#cisfun$ ");
}
