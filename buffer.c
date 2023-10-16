#include "simpleshell.h"

/**
 * buf_clean - A function that cleans the buffer
 * @c: buffer pointer
 * Return: 0 if exist cd in args[0]
 * -1 if otherwise
 */
void buf_clean(char *c)
{
	int ind;

	for (ind = 0; ind < BUFSIZE; ind++)
		c[ind] = 0;
}

/**
 * buf_fil - function that fills the buffer
 * @c: buffer pointer
 * @a: ponter
 * Return: 0 (success)
 * -1 (otherwise)
 */
void buf_fil(char *c, char *a)
{
	int ind;

	for (ind = 0; a[ind] != '\0'; ind++)
		c[ind] = a[ind];
	for (; ind < BUFSIZE; ind++)
		c[ind] = 0;
}
